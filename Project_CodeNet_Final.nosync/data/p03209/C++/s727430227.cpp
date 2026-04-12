#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007;

#define CLR(a) memset((a), 0 ,sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

vector<pair<ll,ll>> bg(55);

ll rec(ll N, ll X){
    if(X <= 0) return 0;
    else if(N == 0) return 1;
    if(X < (bg[N].first+1)/2) return rec(N-1, X-1);
    else if(X == (bg[N].first+1)/2) return bg[N-1].second + 1;
    else return rec(N-1, X-2-bg[N-1].first) + bg[N-1].second + 1;
}

int main(void){
    ll N,X; cin >> N >> X;
    bg[0].first = 1; bg[0].second = 1;
    REP(i,N){
        bg[i+1].first = 2*bg[i].first + 3;
        bg[i+1].second = 2*bg[i].second + 1;
    }
    ll ans = rec(N,X);
    cout << ans << endl;
    return 0;
}