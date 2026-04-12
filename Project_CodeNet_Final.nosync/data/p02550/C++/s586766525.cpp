#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
#define pb push_back
int main(void){
    ll n,x,m;
    cin>>n>>x>>m;
    vector<ll>id(m+1,-1),s;
    ll c=0;
    while(id[x]==-1){
        id[x]=c++;
        s.pb(x);
        x=x*x%m;
    }
    ll d=c-id[x],ans=0;
    if(n<=d){
        rep(0,i,n)ans+=s[i];
    }else{
        rep(0,i,id[x])ans+=s[i];
        n-=id[x];
        ll sum=0;
        rep(0,i,d)sum+=s[id[x]+i];
        ans+=(n/d)*sum;
        n%=d;
        rep(0,i,n)ans+=s[id[x]+i];
    }
    cout<<ans;
}