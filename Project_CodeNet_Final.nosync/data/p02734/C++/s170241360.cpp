#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int N, S, a[3001], d[3001][3001], s[3001];

int main() {
    scanf("%d%d", &N, &S);

    for (int i=1;i<=N;++i) scanf("%d", &a[i]);
    for (int i=1;i<=N;++i) d[i][a[i]] = i;

    for (int i=1;i<=N;++i) {
        for (int j=a[i];j<=S;++j) d[i][j] = (d[i][j] + s[j-a[i]]) % MOD;
        for (int j=0;j<=S;++j) s[j] = (s[j] + d[i][j]) % MOD;
    }
    long long ans = 0;
    for (int i=1;i<=N;++i) {
        ans += 1LL * d[i][S] * (N-i+1);
        ans %= MOD;
    }

    printf("%lld", ans);


}