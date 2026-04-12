#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
#include <cassert>

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair


ll solve(int N, vi& x, vi& y) {
    if (N == 1) return 0;

    vector<ii> xy(N*2);
    rep(i,N) {
        xy[i*2] = ii(x[i], i);
        xy[i*2+1] = ii(y[i], i);
    }
    sort(ALL(xy));

    ll best = LLONG_MAX;
    {
        int amin = xy[0].first, bmax = xy.back().first;
        int amin_at = xy[0].second, bmax_at = xy.back().second;

        int amax = min(x[bmax_at], y[bmax_at]),
            bmin = max(x[amin_at], y[amin_at]);

        rep(i,N) {
            if (i == amin_at || i == bmax_at) continue;
            amax = max(amax, min(x[i], y[i]));
            bmin = min(bmin, max(x[i], y[i]));
        }

        ll da = amax - amin, db = bmax - bmin;
        best = min(best, da * db);
    }
    {
        int amin = xy[0].first, amax = xy.back().first;
        int amin_at = xy[0].second, amax_at = xy.back().second;
        ll da = amax - amin;
        if (amin_at != amax_at) {
            int bmin = max(x[amin_at], y[amin_at]),
                bmax = min(x[amax_at], y[amax_at]);
            if (bmin > bmax) swap(bmin, bmax);

            vector<ii> smaller;
            smaller.reserve(N-2);

            rep(i,N) {
                if (i == amin_at || i == amax_at) continue;
                smaller.pb(ii(min(x[i], y[i]), i));
            }
            sort(ALL(smaller));

            int rmin = bmin, rmax = bmax;
            rep(j,N-2) {
                int wmin = smaller[j].first;
                int wmax = smaller.back().first;
                ll db = max(rmax, wmax) - min(rmin, wmin);
                best = min(best, da * db);

                int i = smaller[j].second;
                int larger = max(x[i], y[i]);
                rmin = min(rmin, larger);
                rmax = max(rmax, larger);
            }
            ll db = rmax - rmin;
            best = min(best, da * db);
        }
    }

    return best;
}

int main() {
    int N;
    scanf("%d", &N);
    vi x(N), y(N);
    rep(i,N){
        scanf("%d %d", &x[i], &y[i]);
    }
    cout << solve(N,x,y) << endl;
    return 0;
}
