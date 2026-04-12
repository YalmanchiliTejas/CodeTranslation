#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    ll N, M;
    cin >> N >> M;
    mat G(N, vec(N, 0));
    REP(i,0,M) {
        ll x, y;
        cin >> x >> y;
        --x; --y;
        G[x][y] = 1;
        G[y][x] = 1;
    }

    ll cnt = 0;
    vec V(N-1);
    REP(i,0,N-1) V[i] = i + 1;
    do {
        ll v = 0, nv;
        bool f = true;
        REP(i,0,N-1) {
            nv = V[i];
            if(G[v][nv] == 0) {
                f = false;
                break;
            }
            v = nv;
        }
        cnt += f;
    } while(next_permutation(ALL(V)));
    PR(cnt);


    return 0;
}

/*



*/