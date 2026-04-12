#include <iostream>
using namespace std;

long long n, a[200005], suf[200005], ans, mod = 1e9+7;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = n-1; i >= 0; i--){
        suf[i] = suf[i+1]+a[i];
        suf[i] %= mod;
    }
    for (int i = 0; i < n; i++){
        ans += a[i]*suf[i+1];
        ans %= mod;
    }
    cout << ans << "\n";
}
