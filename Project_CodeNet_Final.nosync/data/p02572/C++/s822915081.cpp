#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n,ans=0,sum=0; cin>>n;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
      	sum%=mod;
    }
    
    rep(i,n-1){
        sum-=a[i];
        if(sum<0) sum+=mod;
        ans += a[i]*sum;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}