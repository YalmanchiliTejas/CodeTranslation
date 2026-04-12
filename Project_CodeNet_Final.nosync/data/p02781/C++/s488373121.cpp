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

int f(int n){
    if(n==0 || n==1) return 0;
    else return n-1;
}

int main(void){
    string S; cin >> S;
    int K; cin >> K;
    int N = S.size();
    ll dp[N+1][2][K+1]; CLR(dp);
    dp[0][0][0] = 1;
    REP(i,N) dp[i+1][1][0] = 1;
    REP(i,N)REP(k,K){
        if(dp[i][0][k] > 0 && S[i]!='0'){
            dp[i+1][0][k+1] = 1;
        }
        else if(S[i] == '0'){
            dp[i+1][0][k+1] = dp[i][0][k+1];
        }
        dp[i+1][1][k+1] = dp[i][1][k]*9 + dp[i][1][k+1] + dp[i][0][k]*f(S[i]-'0');
        if(S[i] != '0') dp[i+1][1][k+1] += dp[i][0][k+1];
    }
    ll ans = dp[N][0][K] + dp[N][1][K];
    cout << ans << en;
    return 0;
}