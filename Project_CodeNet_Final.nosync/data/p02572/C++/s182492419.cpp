#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

const int mod = 1e9+7;

int n;
long long ar[N];
long long prf[N];

int main(){
    scanf("%d " , &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld" , &ar[i]);
        prf[i] = prf[i - 1] + ar[i];
    }
    long long ans = 0;
    for(int j = 1; j <= n; j++){
        long long cur = (prf[n] - prf[j]) % mod;
        ans += (ar[j] * cur) % mod;
        ans %= mod;
    }
    printf("%lld\n" , ans);
}
