#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<functional>
#include<map>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define PII pair<int,int>
#define PLI pair<long long, int>
#define MOD ((int)1e9 + 7)
#define INF ((int)1e9)
#define INFLL ((LL)1e18)
#define ALL(x) (x).begin(),(x).end()
#define ctoi(x) (x - 'a') 
#define CTOI(x) (x - 'A')
#define BIT(x) (1 << (x))
LL culmod(LL a, LL m){
    long long b = m, u = 1, v = 0;
    while(b){
        long long t = a / b;
        a -= t * b;
        std::swap(a, b);
        u -= t * v;
        std::swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
long long C;
using namespace std;
int main(){
    LL N, M, K;
    cin >> N >> M >> K;
    long long NM = (long long) N * M;
    C=1;
    REPA(i, NM-1){
        C = C * i % MOD;
    }
    REPA(i, K - 1){
        C = (C * culmod(i, MOD))%MOD;
    }
    REPA(i, NM-K+1){
        C = (C * culmod(i, MOD))%MOD;
    }
    long long ans = 0;
    for(LL x = 0;x < N;++x){
        LL d = (x+1)*x/2;
        d%=MOD;
        d*=M*M;
        d%=MOD;
        d*=C;
        d%=MOD;
        ans += d;
        ans %= MOD;
    }
    for(LL y = 0;y < M;++y){
        LL d = (y+1)*y/2;
        d%=MOD;
        d*=N*N;
        d%=MOD;
        d*=C;
        d%=MOD;
        ans += d;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
