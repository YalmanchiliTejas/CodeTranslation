#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long
#define rep(i, a, b) for(int i = a; i <= b; i++)
void read(int &x) {
    x = 0; int flag = 1; char ch = ' ';
    while(ch < '0' || ch > '9') { if(ch == '-') flag = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    x *= flag;
}
void read(ll &x) {
    x = 0; int flag = 1; char ch = ' ';
    while(ch < '0' || ch > '9') { if(ch == '-') flag = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    x *= flag;
}
using namespace std;
const int mod = 1e9 + 7;
int n, a[10010], d;
ll dp[10010][100][2]; // current, mod, limit
void update(ll &x, ll y) { x += y; if(x >= mod) x -= mod; }
int main()
{
    char ch = getchar();
    while(ch >= '0' && ch <= '9') a[++n] = ch - '0', ch = getchar();
    read(d);
    dp[0][0][1] = 1;
    rep(i, 0, n - 1) rep(j, 0, d - 1) {
        update(dp[i + 1][(j + a[i + 1]) % d][1], dp[i][j][1]);
        rep(k, 0, a[i + 1] - 1) update(dp[i + 1][(j + k) % d][0], dp[i][j][1]);
        rep(k, 0, 9) update(dp[i + 1][(j + k) % d][0], dp[i][j][0]);
    }
    printf("%lld\n", (dp[n][0][0] + dp[n][0][1] + mod - 1) % mod);
    return 0;
}