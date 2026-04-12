#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

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
    int H,W; cin >> H >> W;
    char a[H][W]; REP(i,H)REP(j,W) cin >> a[i][j];

    vector<vector<char>> ans;

    REP(i,H){
        bool flag = false;
        REP(j,W){
            if(a[i][j] == '#'){
                flag = true;
                break;
            }
        }
        if(flag){
            vector<char> add(W);
            REP(j,W) add[j] = a[i][j];
            ans.push_back(add);
        }
    }

    vector<vector<char>> ans2(ans.size());
    REP(j,W){
        bool flag = false;
        REP(i,ans.size()){
            if(ans[i][j] == '#'){
                flag = true;
                break;
            }
        }
        if(flag){
            REP(i,ans.size()) ans2[i].push_back(ans[i][j]);
        }
    }
    swap(ans,ans2);
    REP(i,ans.size()){
        for(char c : ans[i]) cout << c;
        cout << endl;
    }
    return 0;
}