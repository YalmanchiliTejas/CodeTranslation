#include <functional>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define NDEBUG

int main()
{
    string t, p;
#ifdef NDEBUG
    cin >> t;
    cin >> p;
#else
    t = "aizucamp";
    p = "azu";
    // t = "abracadabra";
    // p = "rada";
    t = "aabc";
    p = "aabc";
#endif

    t += "$";
    p += "$";

    auto ppc = [](const std::string& s, int n, const std::vector<bool>& v) {
        stringstream ss;
        for (int i = 0; i < s.size(); ++i) {
            if (v[i]) {
                ss << "\033[31m";
            }
            if (i == n) {
                ss << "[" << s[i] << "]";
            }
            else {
                ss << s[i];
            }
            if (v[i]) {
                ss << "\033[0m";
            }
        }
        return ss.str();
    };
    auto pp = [](const std::string& s, int n) {
        stringstream ss;
        for (int i = 0; i < s.size(); ++i) {
            if (i == n) {
                ss << "[" << s[i] << "]";
            }
            else {
                ss << s[i];
            }
        }
        return ss.str();
    };

    vector<bool> exists(p.size() - 1);
    bool duplicated = false;
    int i = 0;
    int j = 0;
    char tmp = '!';
    while (j != t.size()) {
#ifndef NDEBUG
        cout << "T " << pp(t, j) << endl;
        cout << "P " << ppc(p, i, exists) << endl;
        cout << tmp << endl;
        cout << boolalpha << "duplicate: " << duplicated << "\n" << endl;
#endif
        if (p[i] == t[j]) {
            if (!exists[i]) {
                exists[i] = true;
                tmp = p[i];
                i += 1;
            }
        }
        else if (tmp == t[j]) {
            duplicated = true;
        }
        else {
            if (exists[i]) {
                i += 1;
            }
        }
        j += 1;
    }
#ifndef NDEBUG
    cout << "T " << pp(t, j) << endl;
    cout << "P " << ppc(p, i, exists) << endl;
    cout << tmp << endl;
    cout << boolalpha << "duplicate: " << duplicated << "\n" << endl;
#endif
    if (accumulate(begin(exists), end(exists), true, logical_and<>())) {
        if (!duplicated) {
            cout << "yes" << endl;
            return 0;
        }
    }
    cout << "no" << endl;
}