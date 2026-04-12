#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const double EPS = 1e-8;

template<typename T> T chmax(T& a, const T& b){return a = (a > b ? a : b);}
template<typename T> T chmin(T& a, const T& b){return a = (a < b ? a : b);}

#define DEBUG_MODE
#ifdef DEBUG_MODE
#define dump(x) cout << #x << " : " << x << " "
#define dumpL(x) cout << #x << " : " << x << '\n'
#define LINE cout << "line : " << __LINE__ << " "
#define LINEL cout << "line : " << __LINE__ << '\n'
#define dumpV(v) cout << #v << " : ["; for(auto& t : v) cout << t << ", "; cout<<"]" << " "
#define dumpVL(v) cout << #v << " : ["; for(auto& t : v) cout << t << ", "; cout<<"]" << endl
#define STOP assert(false)
#else
#define dump(x) 
#define dumpL(x) 
#define LINE 
#define LINEL 
#define dumpV(v) 
#define dumpVL(v) 
#define STOP assert(false)
#endif
#define mp make_pair
 
namespace std {
template<class S, class T>
ostream &operator <<(ostream& out, const pair<S, T>& a) {
    out << '(' << a.fi << ", " << a.se << ')';
    return out;
}
}

int n;
vi a;

map<pii, ll> dp;

ll calc(int i, int m) {
    if(m == 0) return 0LL;
    if(i >= n) return -INF;
    int d = n - i;
    if((d+1)/2 < m) return -INF;
    if(dp.count({i, m})) return dp[{i, m}];
    
    ll ret = max(a[i] + calc(i+2, m-1), calc(i+1, m));

    return dp[{i, m}] = ret;
}

int main(){
    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
    cout << calc(0, n / 2) << '\n';
    return 0;
}