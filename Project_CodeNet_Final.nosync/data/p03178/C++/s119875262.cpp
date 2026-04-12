#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forlr(i, l, r) for (int i = int(l); i < int(r); i++)
#define repeat(n) for (int hjfjke = 0; hjfjke < int(n); hjfjke++)
#define all(c) c.begin(), c.end()
#define ll long long

const int mod = 1000000007;


int dp[10005][100][2];

int add(int a, int b);
int sub(int a, int b);

int32_t main() {
    std::iostream::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    string s;
    int n, d;
    cin >> s;
    n = s.size();

    cin >> d;

    dp[0][0][1] = true;

    forn(i, n)
    forn(j, d)
    forn(k, 2)
    if (dp[i][j][k] != 0) {
        int lim;
        if (k)
            lim = s[i] - '0';
        else
            lim = 10;

        forn(dig, lim)
            dp[i + 1][(j + dig) % d][0] = add(dp[i + 1][(j + dig) % d][0],  dp[i][j][k]);

        if (k)
            dp[i + 1][(j + s[i] - '0') % d][1] = add(dp[i + 1][(j + s[i] - '0') % d][1],  dp[i][j][k]);
    }

    cout << sub(add(dp[n][0][1], dp[n][0][0]), 1);

    return 0;
}

int add(int a, int b) {
    int result = a + b;
    if (result >= mod)
        result -= mod;
    return result;
}

int sub(int a, int b) {
    int result = a - b;
    if (result < 0)
        result += mod;
    return result;
}