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
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

int main(){
    ll h, w; cin>>h>>w;
    vector<string>grid(h);
    set<ll> ver, hor;
    rep(i,h){
        string s;
        cin>>s;
        grid[i] = s;
    }
    rep(i,h){
        ll cnt=0;
        rep(j,w){
            if(grid[i][j]=='#') cnt++;
        }
        if(cnt==0) hor.insert(i);
    }
    rep(i,w){
        ll cnt=0;
        rep(j,h){
            if(grid[j][i]=='#') cnt++;
        }
        if(cnt==0) ver.insert(i);
    }
    rep(i,h){
        if(hor.count(i)) continue;
        rep(j,w){
            if(ver.count(j)) continue;
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}
