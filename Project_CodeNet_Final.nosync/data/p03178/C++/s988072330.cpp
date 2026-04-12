#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int const maxn = 10101;
int const maxd = 101;
int const mod = 1e9 + 7;

string k;
int di;

int dp9[maxn][maxd];
int dp[maxn][maxd];

int solve9(int idx, int r) {
    if (idx < 0) {
        return r == 0;
    }
    int &d = dp9[idx][r];

    if (d != -1) {
        return d;
    }

    d = 0;

    for (int i = 0, rr = r; i < 10; i++, rr++) {
        if (rr == di) rr = 0;
        d += solve9(idx-1, rr);
        if (d >= mod) {
            d -= mod;
        }
    }

    return d;
}

int solve(int idx, int r) {
    if (idx < 0) {
        return r == 0;
    }

    int &d = dp[idx][r];

    if (d != -1) {
        return d;
    }

    d = 0;

    int x = k[idx] - '0';
    for (int i = 0, rr = r; i < x; i++, rr++) {
        if (rr == di) rr = 0;
        d += solve9(idx-1, rr);

        if (d >= mod) {
            d -= mod;
        }
    }

    d += solve(idx-1, (r + x)%di);

    if (d >= mod) {
        d -= mod;
    }

    return d;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    memset(dp9, -1, sizeof(dp9));

    cin >> k >> di;

    int n = k.size();

    reverse(k.begin(), k.end());

    cout << (solve(n-1, 0)-1+mod)%mod << "\n";
}