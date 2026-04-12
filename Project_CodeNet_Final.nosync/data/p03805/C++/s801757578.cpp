#include <bits/stdc++.h>
#if ONLINE_JUDGE
#define DEBUG false
#else
#define DEBUG true
#endif
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
#define REP(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define rep1(i, n) REP(i, 1, n)
#define rREP(i, k, n) for (int i = (int)(n)-1; i >= k; i--)
#define rrep(i, n) rREP(i, 0, n)
#define forlist(i, vec) for(auto &&i : vec)
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort(all(x))
#define REV(x) reverse(all(x))
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define LOWitr(x, n) lower_bound(all(x), n)
#define UPRitr(x, n) upper_bound(all(x), n)
#define cii(x) int x;cin >> x
#define cill(x) LL x;cin >> x
#define cis(x) string x;cin >> x
#define co(x) cout << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define truecheck assert
#define dump(x) cerr << #x << ": " << (x) << endl
using namespace std;
typedef long long LL;
typedef long long int64;
typedef std::vector<int> VI;
typedef std::vector<VI> VVI;
typedef std::vector<LL> VL;
typedef std::vector<VL> VVL;
typedef std::vector<std::string> VS;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
typedef std::queue<int> QI;
typedef std::priority_queue<int> PQI;
template<class T,class U>inline bool chmax(T &a, const U &b){if (a<b){a=b;return true;}return false;}
template<class T,class U>inline bool chmin(T &a, const U &b){if (b<a){a=b;return true;}return false;}
template<class T,class U>inline void vcinpb(T &v, U n){rep(i, n){typename T::value_type a;cin >> a;v.pb(a);}}

const int INF = 1e9, MOD = 1e9 + 7;
const LL LLINF = 1e16;
// M_PI 3.1415...

int main() {
    fastcin();
    cout << fixed << setprecision(10);
    cill(n);
    cill(m);
    VVL table(10, VL(10));
    VI order;
    rep(i, m){
        cill(a);
        cill(b);
        table[a][b] = 1;
        table[b][a] = 1;
    }
    rep1(i, n+1) order.pb(i);
    LL ans=0;
    do {
        if(order[0]!=1) break;
        rep(i, n-1){
            if(table[order[i]][order[i+1]]==0){
                break;
            }
            if(i==n-2){
                ans++;
            }
        }
    } while (std::next_permutation(order.begin(), order.end()));
    co(ans);
    return 0;
}