#include<bits/stdc++.h>
#define FOR(i,a,b) for(ll i=a; i<=b; ++i)
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
using vl=vector<ll>;
using vp=vector<pll>;
const ll INF=1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,x,m;
    cin>>n>>x>>m;
    ll idx[m+5]={};
    vl sum;
    sum.pb(0);
    FOR(i,1,n){
        ll j=idx[x];
        if(j){
            n-=j;
            ll ans=sum[j-1]+n/(i-j)*(sum[i-1]-sum[j-1]);
            n%=i-j;
            ans+=sum[n+j]-sum[j-1];
            cout<<ans;
            return 0;
        }
        else{
            idx[x]=i;
            sum.pb(sum.back()+x);
        }
        x=x*x%m;
    }
    cout<<sum[n];
    return 0;
}