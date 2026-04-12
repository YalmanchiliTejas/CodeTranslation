#include<bits/stdc++.h>
#include<stdio.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define pb                  push_back
#define arr                 vector<ll>
#define mem(x,val)          memset(x,val,sizeof(x))
#define vp                 vector<pair<ll,ll>>
#define matrix              vector<vector<ll> >
#define digit(x)            floor(log10(x))+1
#define debug(x)            cerr << #x << " is " << x << endl;
#define all(a)              a.begin(),a.end()
#define fixed               setprecision(15)
// ll dx[]={-1,1,0,0},dy[]={0,0,-1,1}; 4 Sides
//ll dx[]={-1,1,-1,1,0,0,-1,1} , dy[]={-1,1,0,0,-1,1,1,-1};    8 Sides
using namespace std;
ll maxx = INT_MIN;  
ll minx = INT_MAX;
ll MOD = (ll)1e9+7;
arr read(ll n){
    arr a;
    for (ll i=0;i<n;i++){
        ll x;
        cin>>x;
        a.pb(x);
    }
    return a;
}
  int main(){
        ll n;
        cin>>n;
        arr a  = read(n);
        arr pre;
        pre.pb(a[0]);
        for (ll i=1;i<a.size();i++){
            pre.pb(a[i]+pre.back());
        }
        ll ans = 0;
        ll cmp = pre.back();
        for (ll i=0;i<a.size()-1;i++){
            ll c = cmp - pre[i];
            c = c%MOD;
            ll d = a[i]%MOD;
            ll e = (c*d)%MOD;
            ans += e%MOD;
        }
        cout<<ans%MOD<<endl;
        return 0;
}
