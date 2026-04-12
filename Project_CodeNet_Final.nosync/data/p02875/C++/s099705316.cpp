#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long fact[10000005];

long long powmod(long long a, long long b){
    long long x = 1;
    long long y = a;
    while(b){
        if(b&1){ x = (x*y)%MOD; }
        y = (y*y)%MOD;
        b >>= 1;
    }
    return x;
}

inline long long ncr(long long a, long long b){
    return fact[a]*powmod((fact[a-b]*fact[b])%MOD, MOD-2)%MOD;
}

int main(){
    int N;
    scanf("%d", &N);

    fact[0] = 1;
    for(int i = 1; i <= N; i ++){
        fact[i] = (fact[i-1]*i)%MOD;
    }

    long long tempPow2 = 1;
    long long ans = 0;
    for(int i = N; i > (N>>1); i --){
        ans += tempPow2*ncr(N, i)%MOD;

        tempPow2 += tempPow2;
        if(tempPow2 >= MOD){tempPow2 -= MOD;}
    }
    //printf("ans(%d)=%lld\n", N, ans);
    ans = (ans+ans)%MOD;
    long long finalAns = (powmod(3, N)-ans+MOD)%MOD;

    printf("%lld", finalAns);
    return 0;
}
