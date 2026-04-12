#include <iostream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cmath>
#include <numeric>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int, int> p_i;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repext(i, a, b) for (int i = a; i < b; i++)
#define reprev(i, n) for (int i = n - 1; i >= 0; i--)
#define repextrev(i, a, b) for (int i = b - 1; i >= a; i--)
#define vec_all(vec) vec.begin(), vec.end()

// vectorデバッグ
template<typename T>
void dump_vec(vector<T> vec) {
    rep(i, vec.size()) {
        cout << i << ": " << vec[i] << endl;
    }
}

// --- notice ---
// intの和はllにしろ

int main() {
    vector<char> all_char;
    rep(i, 26) {
        all_char.push_back('a' + i);
    }

    int n;
    cin >> n;
    vector<string> s(n);

    rep(i, n) {
        cin >> s[i];
    }

    vector<int> char_counts(26, -1);

    int tmp_count;
    rep(i, n) {
        rep(j, all_char.size()) {
            tmp_count = count(s[i].cbegin(), s[i].cend(), all_char[j]);
            if (char_counts[j] == -1) {
                char_counts[j] = tmp_count;
            } else {
                char_counts[j] = min(tmp_count, char_counts[j]);
            }
        }
    }

    rep(i, char_counts.size()) {
        rep(j, char_counts[i]) {
            cout << (char) ('a' + i);
        }
    }

    cout << endl;

    return 0;
}