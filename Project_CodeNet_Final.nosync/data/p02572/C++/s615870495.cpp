#include <iostream>

#define mod (1000000007)
using namespace std;
int main(void){
    long long n;
    cin >> n;
    
    long long a[n];
    long long sum[n+1];
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }
    
    long long ans = 0;
    for(long long i = 0; i < n; i++){
        long long tmp = (sum[n] - sum[i+1]) % mod;
        ans += a[i] * tmp;
        ans %= mod;
    }
    
    cout << ans << endl;
}
