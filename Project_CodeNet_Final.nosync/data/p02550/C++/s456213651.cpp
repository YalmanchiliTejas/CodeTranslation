#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;


int main(){
    ll n,x,m;
    cin >> n >> x >> m;
    map<ll,ll> h;
    ll pos=-1;
    ll ans=0;
    ll cnt=0;
    ll len=0;
    if(n<=m){
        ll s=0;
        while(s<n){
            ans+=x;
            x=x*x;
            x%=m;
            s++;
        }
        cout << ans << endl;
        return 0;
    }
    while(true){
        h[x]=cnt;
        ans+=x;
        x=x*x;
        x%=m;
        cnt++;
        if(h.count(x)){
            pos=h[x];
            break;
        }
    }
    len=cnt-pos;
    ll times=(n-cnt)/len;
    ll r=n-cnt-len*times;
    ll tot=0;
    ll sum=0;
    rep(i,len){
        sum+=x;
        x=x*x;
        x%=m;
    }
    rep(j,r){
        tot+=x;
        x=x*x;
        x%=m;
    }
    cout << ans+times*sum+tot << endl;
    return 0;
}