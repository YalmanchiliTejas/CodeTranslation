#include "bits/stdc++.h"
#define YES "YES"
#define NO "NO"
#define Yes "Yes"
#define No "No"
#define YESNO OUT(three(solve(),YES,NO))
#define YesNo OUT(three(solve(),Yes,No))
#define ECHO OUT(solve())
#define three(A,B,C) ((A)?(B):(C))
#define FOR(i,a,b)  for(LL i=(a);i< (LL)(b);i++)
#define EFOR(i,a,b) for(LL i=(a);i<=(LL)(b);i++)
#define RFOR(i,a,b) for(LL i=(b);i>=(LL)(a);i--)
#define REP(i,b) FOR(i,zero,b)
#define rep REP
#define EREP(i,b) EFOR(i,zero,b)
#define RREP(i,b) RFOR(i,zero,b)
#define ALL(c) c.begin(),c.end()
#define UNIQUE(c) sort(ALL(c));c.erase(unique(ALL(c)),c.end())
#define MAX(c) (*max_element(ALL(c)))
#define MIN(c) (*min_element(ALL(c)))
#define MP make_pair
#define FI first
#define SE second
#define SI(x) (LL(x.size()))
#define PB push_back
#define DEBUG(a) OUT(a)
#define DEBUG2(a,b) OUT2(a,b)
#define cat cout << __LINE__ << endl
#define OUT(a) cout << (a) << endl
#define OUT2(a,b) cout << (a) <<" "<<(b) << endl
#define zero 0LL
#define all ALL
#define pb emplace_back
#define eb pb
#define int long long
using namespace std;
template<typename T> inline void maximize(T &a, T b) { a = max(a, b); }
template<typename T> inline void minimize(T &a, T b) { a = min(a, b); }
template<typename T> inline bool middle(T a, T b, T c) { return b <= a && a <= c; }
template<class T> inline bool MX(T &l, const T &r) { return l < r ? l = r, 1 : 0; }
template<class T> inline bool MN(T &l, const T &r) { return l > r ? l = r, 1 : 0; }
typedef int LL;
typedef double ld;
typedef int ut;
typedef vector<ut> VI;
typedef vector<VI> VII;
typedef pair<ut, ut> pr;
typedef pair<ut, pr> ppr;
typedef vector<pr> Vpr;
typedef vector<ppr> Vppr;
typedef tuple<int, int, int, int> tapu;
typedef vector<tapu> Vtapu;
typedef priority_queue<tapu, Vtapu, greater<tapu> > PQ;
inline void outputVI(VI x) { REP(i, SI(x)) { cout << three(i, " ", "") << x[i]; }OUT(""); }
const int SIZE1 = 3e5 + 1000;
const int SIZE2 = 5010;
const int SIZE3 = 430;
const int SIZE = SIZE1;
const int MAPSIZE = 40;
const LL p = 7 + 1e9;
const LL INF = 1LL << 60;
const long double EPS = 1e-7;
typedef pair<ld, ut> pld;
ut N, M, K, L, Q, D, H, W,R;
VI edges[SIZE];
LL vals[SIZE], answer = zero;
int A[SIZE],B[SIZE];string s[SIZE];
LL BASE=200;
LL additions[SIZE];
VI ans;
LL DP[SIZE][10];
LL solve(){
  cin >> K;
  string FESTIVAL="FESTIVAL";
  LL siz=FESTIVAL.size();
  REP(i,siz-1){
  //  int c=K%BASE;
    FOR(j,i,FESTIVAL.size()-1) ans.pb(j);
    FOR(j,0,BASE)
      ans.pb(i);
   // K/=BASE;
  }
  DP[0][0]=1;
  REP(i,ans.size()){
    REP(j,FESTIVAL.size()+1) DP[i+1][j]=DP[i][j];
    DP[i+1][ans[i]+1]+=DP[i][ans[i]];
  }
  RREP(i,ans.size()-1){
  //  cout << i<< " " <<  K <<" " <<  DP[i][FESTIVAL.size()-1] << endl;
    additions[i]=K/DP[i][FESTIVAL.size()-1];
    K%=DP[i][FESTIVAL.size()-1];  
    if(K==0) break;
  }
  REP(i,ans.size()){
    REP(j,additions[i]){
      cout << 'L';
    }
    cout << FESTIVAL[ans[i]];
  }
	return 0;
} 
 
//!!!!!!!!!!!!!!!!!!!実装を詰める!!!!!!!!!!!!!!!!!!!!!!!!!
signed main() {
 
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	string s;
	solve();
	 
 
	//cin >> N;
	return 0;
 
}
