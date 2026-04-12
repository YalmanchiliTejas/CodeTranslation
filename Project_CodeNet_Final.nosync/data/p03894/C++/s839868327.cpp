#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vp;
const ll INF=99999999999999999;
ll a,b,c,d,e,f,g,ans=0;
int main(){
    ll n,k,s;
    cin>>n>>k;
    vl x(n+2,0);
    x[1]=1;
    s=1;
    x[s-1]=-1;
    x[s+1]=-1;
    rep(i,k){
        cin>>a>>b;
        swap(x[a],x[b]);
        if(a==s)s=b;
        else if(b==s)s=a;
        x[s-1]=-1;
        x[s+1]=-1;
    }

    for(int i=1;i<n+1;i++){
        if(x[i]!=0)ans++;
    }

    cout<<ans<<endl;
}