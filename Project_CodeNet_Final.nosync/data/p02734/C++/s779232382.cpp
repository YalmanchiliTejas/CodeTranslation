#include <bits/stdc++.h>

using namespace std;
typedef long long lolo;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ulolo;

const int maxn = (int)2e5 + 5;
const int INF = 0x3f3f3f3f;
const lolo inf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;
const int MOD = 998244353;

template<class T>
inline void read(T &x) {
    x = 0; T flag = 1;char c;
    do { c = (char) getchar(); if (c == '-') break; } while (c < '0' || c > '9');
    if (c == '-') { c = '0', flag = -1;}
    do { x = x * 10 + c - '0';c = (char) getchar();} while (c >= '0' && c <= '9');
    x *= flag;
}

int a[3003];
int dp[3003];
int main() {
    int n, S;
    read(n);
    read(S);
    lolo ans = 0;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        for (int k = S; k >= a[i]; --k) {
            dp[k] = (dp[k]+dp[k-a[i]])%MOD;
        }
        dp[a[i]] = (dp[a[i]]+i)%MOD;
        ans = (ans + 1LL*dp[S]*(n-i+1)%MOD)%MOD;
        dp[S]=0;
    }
    printf("%lld\n", ans);
    return 0;
}
