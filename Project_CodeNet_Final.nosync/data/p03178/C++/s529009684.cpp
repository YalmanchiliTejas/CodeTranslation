#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

const double EPS = 1e-9;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007; // 998244353

#define CLR(a) memset((a), 0, sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    string K; cin >> K;
    int N = K.size();
    int D; cin >> D;
    ll dp[N+1][2][D]; REP(i,N+1)REP(j,2)REP(k,D) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    REP(i,N)REP(k,D){
        REP(j,10) dp[i+1][1][(k+j)%D] = (dp[i+1][1][(k+j)%D] + dp[i][1][k])%MOD;
        REP(j,K[i]-'0') dp[i+1][1][(k+j)%D] = (dp[i+1][1][(k+j)%D] + dp[i][0][k])%MOD;
        dp[i+1][0][(k+K[i]-'0')%D] = (dp[i+1][0][(k+K[i]-'0')%D] + dp[i][0][k])%MOD;
    }
    ll ans = (dp[N][0][0] + dp[N][1][0] -1 + MOD)%MOD;
    cout << ans << endl;
    return 0;
}