#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli BP[51] = { 1 }, B[51] = { 1 };

lli rec(int lev, lli num) {
    if (num <= 0) return 0;
    if (lev == 0) return 1;

    lli res = 0;
    
    if (num >= BP[lev]/2 + 1) res += B[lev-1] + 1 + rec(lev-1, num-BP[lev-1]-2);
    else res += rec(lev-1, num-1);

    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    lli n, x;
    cin >> n >> x;

    // init
    for (int i=1; i<=n; i++) {
        B[i] = B[i-1]*2 + 1;
        BP[i] = BP[i-1]*2 + 3;
    }

    cout << rec(n, x) << endl;

    return 0;
}
