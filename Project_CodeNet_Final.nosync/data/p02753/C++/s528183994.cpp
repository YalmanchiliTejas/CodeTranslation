#include <bits/stdc++.h>
#include <stdio.h>

#define REP(i, n) for (int i=0; i<n; i++)
#define print(x) cout << x << endl

typedef long long ll;

using namespace std;

void solve() {
    string S;
    cin >> S;

    bool flag = true;
    for (int i = 1; i < S.length(); i++) {
        if (S[0] != S[i]) {
            flag = false;
            break;
        }
    }
    if (flag) print("No");
    else print("Yes");
}

signed main() {
    solve();
}
