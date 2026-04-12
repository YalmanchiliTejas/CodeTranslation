#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))
 
using namespace std;
 
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
 
const ll INF=1e9+7;

int main(){
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans=0;
    if(c<=a+b){
        ll ans=INF;
        rep(i,100001){
            ll p=max(0LL,x-i);
            ll q=max(0LL,y-i);
            ans=min(ans,p*a+q*b+2*i*c);
        }
        cout << ans << endl;
    }
    else{
        cout << a*x+b*y << endl;
    }
    return 0;
} 