//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main(){
    int H, W;
    char a[100][100];
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) cin >> a[i][j];
    }

    for(int i = 0; i < H; i++) {
        bool is_rm = true;
        for(int j = 0; j < W; j++) {
            if(a[i][j] == '#'){
                is_rm = false;
                break;
            }
        }
        if(is_rm) {
            H--;
            for(int k = i; k < H; k++) {
                for(int l = 0; l < W; l++) {
                    a[k][l] = a[k+1][l];
                }
            }
            i--;
        }
    }

    for(int j = 0; j < W; j++) {
        bool is_rm = true;
        for(int i = 0; i < H; i++) {
            if(a[i][j] == '#'){
                is_rm = false;
                break;
            }
        }
        if(is_rm) {
            W--;
            for(int k = j; k < W; k++) {
                for(int l = 0; l < H; l++) {
                    a[l][k] = a[l][k + 1];
                }
            }
            j--;
        }
    }

    REP(i, H) {
        REP(j, W) cout << a[i][j];
        cout << endl;
    }

    return 0;
}
