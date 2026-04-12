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
const int maxn = 3010;
int n, a[maxn];
ll dp[maxn][maxn];
int main()
{
    read(n);
    rep(i, 1, n) read(a[i]), dp[i][i] = a[i];
    rep(len, 2, n) rep(l, 1, n - len + 1) {
        int r = l + len - 1;
        dp[l][r] = max(-dp[l + 1][r] + a[l], -dp[l][r - 1] + a[r]);
    }
    printf("%lld\n", dp[1][n]);
    return 0;
}