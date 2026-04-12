#include <bits/stdc++.h>
//#define int ll
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int MAX = 2e5 + 10;
using namespace std;
ll a[MAX];
void solve() {
    ll n,sum=0,ans=0;
    cin>>n;
    for (int i = 0; i < n; ++i)
        cin>>a[i],sum+=a[i]%mod;
    for(int i=0;i<n;i++)
        ans=(((sum-a[i])%mod*a[i]%mod)+ans)%mod;
    cout<<(ans%2==0?ans/2:(ans+mod)/2)<<endl;
}

signed main() {
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _ = 1;
//    cin>>_;
    while (_--) {
        solve();
    }
    return 0;
}