#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = (int)1e9 + 7;
int INF = (int)2e18;
// Comment out below and program paste

// #include "UnionFind.hpp"
// #include "power.hpp"

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    for (int i = 0; i < S.length() - 1; i++) {
        if (S.substr(i, 2) == "AC") {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
