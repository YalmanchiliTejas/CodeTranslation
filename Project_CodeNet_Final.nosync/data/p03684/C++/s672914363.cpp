#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// template {{{  0 
// using {{{ 1
using ll = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
// }}} 1
// definition {{{ 1
// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define Scll(x) scanf("%lld", &x)
#define Scll2(x,y) scanf("%lld%lld", &x, &y)
#define Scll3(x,y,z) scanf("%lld%lld%lld", &x, &y, &z)
#define Scc(c) scanf("%c", &c);
#define Scs(s) scanf("%s", s);
#define Scstr(s) scanf("%s", &s);
// }}} 2
// constants {{{ 2
#define EPS (1e-7)
#define INF (2e9)
#define PI (acos(-1))
// }}} 2
// systems {{{ 2
#define Repe(x,y,z) for(ll x = z; x < y; x++)
#define Rep(x,y) Repe(x,y,0)
#define RRepe(x,y,z) for(ll x = y-z-1; x >= 0; x--)
#define RRep(x,y) RRepe(x,y,0)
// }}} 2
// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n")
#define YESNO(a) (a)?printf("YES\n"):printf("NO\n")
// }}} 2
// }}} 1
// input {{{ 1
// }}} 1
// }}} 0

int main() {

    int N;
    Scd(N);
    vii a(N);
    vii b(N);
    int x,y;
    Rep(i,N){
        Scd2(x,y);
        a[i] = {x,i};
        b[i] = {y,i};
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    vector<vii> e(N);
    int u,v,c;
    Repe(i,N,1){
        u = a[i-1].second; v = a[i].second; c = abs(a[i-1].first - a[i].first);
        e[u].push_back({v,c}); e[v].push_back({u,c});
        u = b[i-1].second; v = b[i].second; c = abs(b[i-1].first - b[i].first);
        e[u].push_back({v,c}); e[v].push_back({u,c});
    }

    vi id(N,-1);
    priority_queue<pii,vector<pii>,greater<pii>> q;

    q.push({0,0});
    int ans = 0;
    while( q.size() ){
        int from = q.top().second;
        int cost = q.top().first;
        q.pop();
        if( id[from] != -1 ) continue;
        id[from] = 0;
        ans += cost;
        for( pii tow : e[from] ){
            q.push({tow.second,tow.first});
        }
    }

    printf ("%d\n", ans );

    return 0;

}

