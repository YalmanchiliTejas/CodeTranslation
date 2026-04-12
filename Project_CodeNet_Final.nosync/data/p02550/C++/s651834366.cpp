#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define bitsz(x) int(__builtin_popcount(x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(x) push_back(x)
#define INF 1e9
#define LINF 1e18
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int di[4] = {1,0,-1,0};
const int dj[4] = {0,1,0,-1};
const int mod = 1000000007;
//const int mod = 998244353;


int main() {
    ll n,x,m; cin >> n >> x >> m;
    vector<int> id(m,-1); //余りxにいつ到達したか
    vector<int> a; //通った余り
    int len = 0; //全体の長さ
    ll tot = 0; //全体の和
    while (id[x] == -1) {
        a.push_back(x);
        id[x] = len;
        len++;
        tot += x;
        x = (x*x)%m;
    }
    int c = len - id[x]; //周期の長さ
    ll s = 0; //周期の和
    for (int i=id[x]; i<len; i++) {
        s += a[i];
    }
    ll ans = 0;
    if (n <= len) {
        rep(i,n) ans += a[i];
    } else {
        ans += tot;
        n -= len;
        ans += s*(n/c);
        n %= c;
        rep(i,n) ans += a[id[x]+i];
    }
    cout << ans << endl;
}