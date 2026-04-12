#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

typedef long long LL;
const int MAX = 100001 * 2;
const LL MOD = 1000000007;

long long fact[MAX];
long long inv[MAX];


LL mod_pow(LL x,LL n){
    LL ret = 1;

    while(n){
        if(n & 1)ret = ret * x % MOD;
        x = x * x % MOD;
        n /= 2;
    }

    return ret;
}

LL mod_P(int n,int k){
    return fact[n] * inv[n - k] % MOD;
}

LL mod_C(int n,int k){
    return mod_P(n,k) * inv[k] % MOD;
}

void init(){
    fact[0] = inv[0] = 1;
    for(int i = 1;i < MAX;i++){
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = mod_pow(fact[i],MOD - 2);
    }
}

int main(){
    init();
    int N,M,K;
    long long x = 0,y = 0;

    cin >> N >> M >> K;

    for(long long i = 0;i < N;i++)x += i * (N-i) * pow(M,2);
    for(long long i = 0;i < M;i++)y += i * (M-i) * pow(N,2);

    cout << mod_C(N*M - 2,K-2) * ((x + y) % MOD) % MOD << endl;

    return 0;
}