#include <bits/stdc++.h>
using namespace std;
long mod = 1e9+7;
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
int main(void){
    long n;
    cin >> n;
    long a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    long sum = 0,sum2=0;
    for(int i=0;i<n;i++){
        sum += a[i];
        sum %= mod;
    }
    for(int i=0;i<n;i++){
        sum2 += (a[i]*a[i])%mod;
        sum2 %= mod;
    }
    long ans = (sum*sum)%mod-sum2;
    if(ans<0) ans += mod;
    long inv2 = modinv(2,mod);
    cout << (ans*inv2)%mod << endl;
}