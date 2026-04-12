#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define fr first
#define se second
const ll mod = 998244353;

void solve(ll cas){
    ll n,x,m;
    cin>>n>>x>>m;
    unordered_set<ll> s;
    vector<ll> v;
    while(s.find(x)==s.end()){
        v.pb(x);
        s.insert(x);
        x = (x%m * x%m)%m;
    }
    ll idx;
    for(ll i=0;i<v.size();i++){
        if(v[i]==x){
            idx=i;break;
        }
    }
    ll ans=0;
    if(n<v.size()){
        for(ll i=0;i<n;i++) ans+=v[i];
        cout<<ans<<endl;
        return;
    }

    for(ll i=0;i<idx;i++){
        ans+=v[i];
        n--;
    }
    ll q=n/(v.size()-idx), r=n%(v.size()-idx);
    ll sum=0;
    for(ll i=idx;i<v.size();i++){
        sum+=v[i];
    }
    ans += sum*q;
    for(ll i=idx,j=0;j<r;j++,i++){
        ans+=v[i];
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll qu=1;
    // cin>>qu;
    for(ll cas=1;cas<=qu;cas++){
        solve(cas);
    }
}
