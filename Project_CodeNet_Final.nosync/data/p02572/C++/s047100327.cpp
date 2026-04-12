#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define BIG_PRIME 1000000007

#define rep(i,n) for(int i=0;i<(n);++i)

int main()
{
    int n; cin >> n;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    ll horizontal_sum = a[n-1];
    ll ans = 0;
    for (int i = n-2;i>=0;--i){
        ans+=horizontal_sum*a[i];
        ans%=BIG_PRIME;
        horizontal_sum+=a[i];
        horizontal_sum%=BIG_PRIME;
    } 
    cout << ans << endl;
    return 0;
}
