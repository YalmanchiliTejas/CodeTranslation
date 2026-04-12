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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

const double EPS = 1e-9;
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
    int H,W; cin >> H >> W;
    char A[H][W];
    set<P> s;
    REP(i,H)REP(j,W){
        cin >> A[i][j];
        if(A[i][j] == '#') s.insert(P(i,j));
    }
    s.erase(P(0,0));
    int x = 0, y = 0;
    while(x != H-1 || y != W-1){
        if((x<H-1 && A[x+1][y]=='#') ^ (y<W-1 && A[x][y+1]=='#')){
            if(A[x+1][y]=='#') x++;
            else y++;
            s.erase(P(x,y));
        }
        else{
            cout << "Impossible" << endl;
            return 0;
        }
    }
    if(s.size()) cout << "Impossible" << endl;
    else cout << "Possible" << endl;
    return 0;
}