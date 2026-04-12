#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

template<typename T>void read(T&x){x=0;int fl=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')
fl=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}x*=fl;}
template<typename T,typename...Args>inline void read(T&t,Args&...args){read(t);read(args...);}

typedef long long LL;

const int N = 3005;
const LL MOD = 998244353;

int n;
LL S, a[N], dp[N][N], ans, sum[N][N];

int main(){
    read(n, S);
    for(int i = 1; i <= n; i++) read(a[i]);
    for(int k = 1; k <= n; k++){
        (dp[k][a[k]] += k) %= MOD;
        for(int s = a[k] + 1; s <= S; s++)
            (dp[k][s] += sum[k-1][s-a[k]]) %= MOD;
        for(int s = 0; s <= S; s++)
            sum[k][s] = (sum[k-1][s] + dp[k][s]) % MOD;
    }
    for(int i = 1; i <= n; i++)
        (ans += dp[i][S] * (n - i + 1) % MOD) %= MOD;
    printf("%lld\n", ans);
    return 0;
}