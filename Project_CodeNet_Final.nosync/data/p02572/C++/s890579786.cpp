#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long mod = 1e9+7;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for(long long i = 0; i < n; i++) cin >> a[i], sum += a[i];

    long long ans = 0;
    for(long long i = 0; i < n; i++){
        sum -= a[i];
        ans += a[i] * (sum%mod);
        ans %= mod;
    }
    
    cout << ans << endl;
    return 0;
}