#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
using ll=long long;
using pint=pair<int,int>;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define el '\n'
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl
#define $in(v,n) ;rep(II,0,n)cin>>v[II]
inline void IN(void){return;}
template<typename F,typename... R>inline void IN(F& f, R&... r){cin>>f;IN(r...);}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

ll n, x, m;
int main(){
    IN(n, x, m);
    vector<int> id(m, -1), graph;
    ll cnt, tot; cnt = tot = 0;
    while(id[x] == -1){
        id[x] = cnt; cnt++;
        tot += x;
        graph.push_back(x);
        x = (x*x)%m;
    }

    if(n <= cnt){
        ll ans = 0;
        rep(i, 0, n) ans += graph[i];
        cout << ans << el;
        return 0;
    }

    ll cycle = cnt - id[x];
    ll sum = 0; rep(i, id[x], cnt) sum += graph[i];

    ll ans = tot;
    n -= cnt;
    ans += sum*(n/cycle);
    n %= cycle;
    rep(i, 0, n) ans += graph[id[x]+i];
    cout << ans << el;

    return 0;
}
