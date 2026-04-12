#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
map<int, int> H[2];
set<int> S[2];
typedef pair<int, int> PII;
typedef long long LL;
vector<PII> V;



inline void Insert(int x, int v){
    H[x][v]++;
    S[x].insert(v);
}
inline void Erase(int x, int v){
    if(H[x][v] == 1) S[x].erase(v);
    H[x][v]--;
}
int N, x, y;
int Rmax, Rmin, Bmax, Bmin, tRmax, tRmin, tBmax, tBmin;
int main()
{
    cin>>N;
    for(int i = 0; i < N; i++){
        scanf("%d %d", &x, &y);
        if(x < y) swap(x, y);
        V.pb(mp(x, y));
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    LL ans = 2e18;
    for(auto x : V){
        Insert(0, x.fi);
        Insert(1, x.se);
    }
    Rmax = Rmin = V[0].fi;
    Bmax = Bmin = V[0].se;
    Erase(0, V[0].fi); Erase(1, V[0].se);
    for(int i = 1; i < V.size(); i++){
        tRmax = Rmax;
        tRmin = Rmin;
        tBmax = Bmax;
        tBmin = Bmin;
        tRmin = min(tRmin, V[i].se);
        tBmax = max(tBmax, V[i].fi); tBmin = min(tBmin, V[i].fi);
        Erase(0, V[i].fi); Erase(1, V[i].se);
        if(S[0].size() > 0){
            tRmin = min(tRmin, *S[1].begin());
            tBmin = min(tBmin, *S[0].begin());
        }
        ans = min(ans, (LL)(tRmax - tRmin)*(tBmax - tBmin));
        Rmin = min(Rmin, V[i].fi);
        Bmax = max(Bmax, V[i].se); Bmin = min(Bmin, V[i].se);
    }
    ans = min(ans, (LL)(Rmax - Rmin)*(Bmax - Bmin));
    cout<<ans<<endl;
}
