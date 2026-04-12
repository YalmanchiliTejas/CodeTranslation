/* One original thought is worth a thousand mindless quotings */

#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<bitset>
#include<queue>
#define ll long long
#define ld long double
#define ull unsigned long long
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout.precision(10);cout << fixed;
#define dbset(x) for(int i=0 ; i<x.size(); i++) cerr << x[i] << " "; cerr << endl;
#define inf 1000000007
#define INF 1000000000000000000LL
#define PI 3.14159265358979323846
#define mod 1000000007
#define mod1 1000696969
#define flusz fflush(stdout);
#define VI vector<int>
#define VPI vector < pair<int,int> >
#define PII pair<int, int>
#define BIT bitset<N>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORR(x, y, z) for(int x = y; x >= (z); --x)
using namespace std;

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

#define int long long
const int N = 5 * 100*1000 + 7;

int test;

int n,m,s,t;

VPI g[N];

int dist[N];

set <PII> S;

int res;

int dp1[N],dp2[N];

VI G;

void dij(){
    FOR(i,1,n){
        dist[i] = ( i == s ? 0 : INF);
        S.insert(mp(dist[i],i));
    }

    while(!S.empty()){
        auto it = *S.begin();
        S.erase(it);

        for(auto it1:g[it.nd]){
            if (dist[it1.st] > it.st + it1.nd){
                S.erase(mp(dist[it1.st],it1.st));

                dist[it1.st] = it.st + it1.nd;

                S.insert(mp(dist[it1.st],it1.st));
            }
        }
    }
}

bool cmp(int a,int b){
    return dist[a] < dist[b];
}

void solve()
{
    cin >> n >> m >> s >> t;

    FOR(i,1,m){
        int a,b,c;
        cin >> a >> b >> c;

        g[a].eb(b,c);
        g[b].eb(a,c);
    }

    dij();

    FOR(i,1,n){
        G.pb(i);
    }

    sort(G.begin(),G.end(),cmp);

    dp1[s] = 1;

    for(auto it:G){
        for(auto it1:g[it]){
            if (dist[it] + it1.nd == dist[it1.st]){
                dp1[it1.st] += dp1[it];
                dp1[it1.st] %= mod;
            }
        }
    }

    reverse(G.begin(),G.end());

    dp2[t] = 1;

    for(auto it:G){
        for(auto it1:g[it]){
            if (dist[it] - it1.nd == dist[it1.st]){
                dp2[it1.st] += dp2[it];
                dp2[it1.st] %= mod;
            }
        }
    }  

    FOR(i,1,n){
        if (dist[i]*2 == dist[t]){
            res += ( ( (dp1[i] * dp1[i]) % mod) * ((dp2[i] * dp2[i]) % mod) ) % mod; 
        }

        res %= mod;

        for(auto it:g[i]){
            if ( dist[i] * 2 < dist[t] && dist[it.st] * 2 > dist[t] && dist[it.st] == dist[i] + it.nd ){
                res += ( ( (dp1[i] * dp1[i]) % mod) * ((dp2[it.st] * dp2[it.st]) % mod) ) % mod; 
                res %= mod;
            }
        }
    } 

    cout << (mod+(dp1[t]*dp1[t])%mod-res)%mod;

    return;
}

int32_t main()
{
    boost

    test=1;

    while(test--)
    {
        solve();
    }

  return 0;
}
