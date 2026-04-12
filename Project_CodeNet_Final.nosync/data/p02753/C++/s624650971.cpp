#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

#define ll long long
#define el '\n'
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repi(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define mp make_pair
#ifdef LOCAL
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define check(...) assert(__VA_ARGS__)
#else
#define debug(fmt, ...)
#define check(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    bool a = false;
    bool b = false;
    for (auto x : s) {
        if (x == 'A') {
            a = true;
        } else {
            b = true;
        }
    }
    if (a && b) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
