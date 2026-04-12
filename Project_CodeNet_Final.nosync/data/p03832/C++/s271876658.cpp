#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pw(x) (1LL<<(x))
static const int fast_io = [](){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
static const int precise_doubles = [](){cout<<fixed<<setprecision(20);return 0;}();
typedef pair<int, int> PII;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order(k) - iterator to kth largest, order_of_key(k) - #things < k
typedef long double LD;
typedef long long LL;
#define EVAL(x) x
#define SPA(x) EVAL({cout << #x" = " << x << ' ';})
#define NEWL EVAL({cout << '\n';})
#define SPAR(a, b) EVAL({cout<<#a" = ";for(auto it=a;it!=b;)cout<<*(it++)<<" ";cout<<'\n';})
#define SPAV(v) EVAL({cout<<#v" = ";for(auto it=v.begin();it!=v.end();)cout<<*(it++)<<" ";cout<<'\n';})
const int INF = 0x3f3f3f3f; // 1.0e9
const LL LINF = 0x3f3f3f3f3f3f3f3fll; // 4.5e18
const LD eps = 1e-20;
const int mod = 1e9 + 7;
inline int msum(int x, int y) {return (x+y<mod ? x+y : x+y-mod);}
inline int mdif(int x, int y) {return (x>=y ? x-y : x-y+mod);}
inline int mprod(int x, int y) { return (1ll*x*y) % mod; }
inline int mpow(int x, LL y) {LL r=1;while(y){if(y&1)r=mprod(r,x);x=mprod(x,x);y>>=1;}return r;}
inline int minv(int x) { return mpow(x, mod-2); }
#define DIE EVAL({cout << -1 << '\n'; exit(0);})
//------------------------------------------------------------------------------------------------------

const int N = 1e3 + 10;
int n, a, b, c, d;
int fac[N], ifac[N];

void pre() {
    fac[0] = ifac[0] = 1;
    FOR(i, 1, N) {
        fac[i] = mprod(fac[i-1], i);
        ifac[i] = minv(fac[i]);
    }
}

int getways(int sz, int groups_of_sz) {
    int ret = mprod(fac[sz * groups_of_sz], ifac[groups_of_sz]);
    ret = mprod(ret, minv(mpow(fac[sz], groups_of_sz)));
    return ret;
}

int Choose(int z, int k) {
    if(z < 0 or k < 0 or z < k) return 0;
    return mprod(fac[z], mprod(ifac[z-k], ifac[k]));
}

int main() {
    pre();
    cin >> n >> a >> b >> c >> d;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    FOR(sz, a, b+1) {
        vector<int> newdp(n+1, 0);
        FOR(people, 0, n+1) {
            newdp[people] = msum(newdp[people], dp[people]);
            FOR(groups_of_sz, c, d+1) {
                int new_people = people + sz * groups_of_sz;
                if(new_people > n) break;
                newdp[new_people] = msum(newdp[new_people],
                    mprod(getways(sz, groups_of_sz),
                        mprod(Choose(new_people, people), dp[people])));
            }
        }
        dp = newdp;
    }
    cout << dp[n] << '\n';
}




























