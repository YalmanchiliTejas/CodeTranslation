#include <iostream>
using namespace std;

long long n, a[200005], suf[200005], mod = 1e9+7;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long sum = a[n-1];
    suf[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--){
        sum += a[i];
        sum %= mod;
        suf[i] = sum;
    }
    long long ans = 0;
    for (int i = 0; i < n-1; i++){
        ans += a[i]*suf[i+1];
        ans %= mod;
    }
    cout << ans << "\n";
}
