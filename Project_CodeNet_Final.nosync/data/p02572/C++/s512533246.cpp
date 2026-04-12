#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define N 200005
#define mod 1000000007
using namespace std;
ll a[N],sum[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sum[n]=a[n];
    for(int i=n-1;i>0;i--) sum[i]=(sum[i+1]+a[i])%mod;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll p=(sum[i+1]*a[i])%mod;
        ans=(ans+p)%mod;
    }
    cout<<ans;
}
int main()
{
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
