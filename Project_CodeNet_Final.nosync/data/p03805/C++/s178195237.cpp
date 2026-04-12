#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i=0; i < n; i++)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define all(vec) vec.begin(), vec.end()
#define tmax(x, y, z) max((x), max((y), (z)))
#define tmin(x, y, z) min((x), min((y), (z)))
ll MM = 1000000000; ll mod = MM + 7; ll MMM=9223372036854775807;//2^63 -1
ll GCD(ll x, ll y){ if(y == 0) return x; else return GCD(y, x % y);}
ll LCM(ll x, ll y){ return x / GCD(x, y) * y;}
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true;} return false;}
const ll INF = 1LL << 60;
//cout << fixed << setprecision(10);

int main(){
    ll ans=0, n, m; cin>>n>>m;
    vector<set<ll>> v(n+1);
    ll a, b;
    rep(i,m) cin>>a>>b, v[a].insert(b), v[b].insert(a);
    vector<ll> s(n-1);
    rep(i,n-1) s[i]=i+2;
    do{
        bool ok=1;
        if(!v[1].count(s[0])) continue;
        rep(i,n-2){
            if(!v[s[i]].count(s[i+1])){
                ok=0;
                break;
            }
        }
        if(ok) ans++;
    }while(next_permutation(all(s)));

    cout<<ans<<endl;
}