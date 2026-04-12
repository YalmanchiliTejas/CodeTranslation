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

const ll INF=1e18;
const ll mod=1e9+7;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    deque<ll> d,ans;
    rep(i,n){
        d.push_back(a[i]);
    }
    ll be=*d.begin();
    d.pop_front();
    ans.push_back(be);
    rep(i,n-1){
        ll val=-1;
        if((i/2)%2==0){
            val=*d.rbegin();
            d.pop_back();
        }
        else{
            val=*d.begin();
            d.pop_front();
        }
        if(i%2==0){
            ans.push_back(val);
        }
        else{
            ans.push_front(val);
        }
    }
    ll sum=0;
    ll v=*ans.begin();
    ans.pop_front();
    rep(i,n-1){
        ll x=*ans.begin();
        ans.pop_front();
        sum+=abs(v-x);
        v=x;
    }
    
    rep(i,n){
        d.push_back(a[i]);
    }
    ll st=*d.rbegin();
    d.pop_back();
    ans.push_back(st);
    rep(i,n-1){
        ll val=-1;
        if((i/2)%2==1){
            val=*d.rbegin();
            d.pop_back();
        }
        else{
            val=*d.begin();
            d.pop_front();
        }
        if(i%2==1){
            ans.push_back(val);
        }
        else{
            ans.push_front(val);
        }
    }
    ll tot=0;
    ll w=*ans.begin();
    ans.pop_front();
    rep(i,n-1){
        ll x=*ans.begin();
        ans.pop_front();
        tot+=abs(w-x);
        w=x;
    }
    cout << max(sum,tot) << endl;
    return 0;
}
