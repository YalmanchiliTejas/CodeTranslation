#include <bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long int;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1e11;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
ll a[51];
ll p[51];
ll init(int n){
    a[0] = 1;
    p[0] = 1;
    rep(i,n){
        a[i+1] = 2*a[i]+3;
        p[i+1] = 2*p[i]+1;
    }
}
ll burger(ll k,ll x){
    if (x == 0) return 0;
    if (k == 0) return 1;
    if (x <= a[k-1]+1) return burger(k-1,x-1);
    else return burger(k-1,x-a[k-1]-2)+p[k-1]+1;
}
int main(){
    ll n,x;
    cin >> n >> x;
    init(n);
    PRINT(burger(n,x));
}