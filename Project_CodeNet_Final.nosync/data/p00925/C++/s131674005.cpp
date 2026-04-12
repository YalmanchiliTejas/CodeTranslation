#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;

    auto multiplicationFirst = [](const string& s) {
        // value or operator
        enum class T { V, O };
        vector<pair<T, int>> v;
        for (char i : s) {
            if (i == '*' || i == '+') {
                v.emplace_back(T::O, i);
            }
            else {
                v.emplace_back(T::V, i - '0');
            }
        }
        while (true) {
            if (find(begin(v), end(v),
                     make_pair(T::O, static_cast<int>('*'))) == end(v)) {
                break;
            }
            vector<pair<T, int>> t;
            for (size_t i = 0; i < v.size(); ++i) {
                if (v[i] != make_pair(T::O, static_cast<int>('*'))) {
                    t.push_back(v[i]);
                }
                else {
                    t.pop_back();
                    t.emplace_back(T ::V, v[i - 1].second * v[i + 1].second);
                    copy(begin(v) + i + 2, end(v), back_inserter(t));
                    break;
                }
            }
            v = t;
        }
        return accumulate(begin(v), end(v), 0,
                          [](int a, const pair<T, int>& b) {
                              if (b.first == T::O) {
                                  return a;
                              }
                              else {
                                  return a + b.second;
                              }
                          });
    };
    auto leftToRight = [](const string& s) {
        int accumulator = s[0] - '0';
        for (size_t i = 1; i < s.size() - 1; i += 2) {
            if (s[i] == '+') {
                accumulator += s[i + 1] - '0';
            }
            else {
                accumulator *= s[i + 1] - '0';
            }
        }
        return accumulator;
    };
    auto mf = multiplicationFirst(s);
    auto lr = leftToRight(s);
    if (mf == n && lr == n) {
        cout << 'U' << endl;
    }
    else if (mf == n) {
        cout << 'M' << endl;
    }
    else if (lr == n) {
        cout << 'L' << endl;
    }
    else {
        cout << 'I' << endl;
    }
}
