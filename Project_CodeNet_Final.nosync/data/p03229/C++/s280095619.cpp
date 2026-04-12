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

int main(void){
    int N; cin >> N;
    vector<ll> A(N); REP(i,N) cin >> A[i];
    SORT(A); REVERSE(A);
    ll ans = 0, ans1 = 0, ans2 = 0;
    if(N%2){
        REP(i,(N+1)/2-2) ans1 += 2*A[i];
        ans1 += A[(N+1)/2-2] + A[(N+1)/2-1];
        REP(i,N/2) ans1 -= 2*A[N-1-i];

        REP(i,N/2) ans2 += 2*A[i];
        REP(i,(N+1)/2-2) ans2 -= 2*A[N-1-i];
        ans2 -= A[(N+1)/2-1] + A[(N+1)/2];
    }
    else{
        REP(i,N/2-1) ans1 += 2*A[i];
        ans1 += A[N/2-1];
        REP(i,N/2-1) ans1 -= 2*A[N-1-i];
        ans1 -= A[N/2];
    }
    ans = max(ans1, ans2);
    cout << ans << endl;
    return 0;
}