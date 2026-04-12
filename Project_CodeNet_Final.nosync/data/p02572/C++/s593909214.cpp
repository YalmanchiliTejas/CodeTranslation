#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a[200010];
    long long sum = 0,b[200010];
    cin >> n;
    b[0] = 0;
    a[0] = 0;
    long long mod = 1000000007;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = (b[i-1]+a[i-1]) % mod;
    }
    for(int i = 1; i <= n; i++){
        sum = (sum + a[i]*b[i]%mod)%mod;
    }
    cout << sum << endl;
  return 0;
}
