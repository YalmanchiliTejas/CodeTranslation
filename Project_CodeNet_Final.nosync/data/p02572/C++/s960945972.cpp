#include <iostream>

using namespace std;
const int N = 2e5 + 1;
const int mod = 1e9 + 7;
long long a[N];
int n;
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i] = a[i - 1] + a[i];
    long long ans = 0;
    for (int i = 1; i < n; i++){
        long long p = (a[i] - a[i - 1] + mod) % mod;
        ans = (ans + (p % mod * ((a[n] - a[i] + mod) % mod))) % mod;
    }
    cout << ans;
    return 0;
}   