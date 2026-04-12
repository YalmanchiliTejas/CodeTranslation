#include <bits/stdc++.h>
using namespace std;
int const MX = 2e5 + 2, MOD = 1e9 + 7;
long long a[MX];
int main()
{
    int n;
    cin>>n;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum += a[i];
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        long long s = (((sum - a[i]) % MOD)*a[i]) % MOD;
        ans = ans + s;
        sum -= a[i];
        ans = ans % MOD;
    }
    cout<<ans % MOD;
}


