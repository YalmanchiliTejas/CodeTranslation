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

const ll mod=1e9+7;


int main(){
    ll n;
    cin >> n;
    multiset<ll> a;
    ll ans=0;
    rep(i,n){
        ll x;
        cin >> x;
        auto it=a.lower_bound(x);
        if(it==a.begin()){
            a.insert(x);
        }
        else{
            it--;
            ll v=*it;
            a.erase(a.find(v));
            a.insert(x);
        }
    }
    cout << a.size() << endl;
    return 0;
}