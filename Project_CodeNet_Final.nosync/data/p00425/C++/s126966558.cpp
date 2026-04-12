// template ver2.02

// include
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <complex>

using namespace std;

// conversion
inline int to_int(string s) {int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string to_str(T x) {ostringstream sout; sout << x; return sout.str();}

// typedef
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

// util
#define MP make_pair
#define EACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define CLR(a) memset((a), 0 , sizeof(a))
template<class T, class C> inline bool in(T e, C c) {return c.find(e) != c.end();}
template<class T> inline bool in(T x, T a, T b) {return a <= x && x < b;}

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define RREP(i, n) RFOR(i, 0, n)

// IO
#define PRA(a, n) cout << a[0]; FOR(itr, 1, n) {cout << " " << a[itr];} cout << endl;
#define PRF(x, w) cout << setprecision((w)); cout << setiosflags(ios::fixed); cout << (x) << endl;

// constant
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INF = (int)1e9;
const int DI[] = {0, 1, 0, -1};
const int DJ[] = {1, 0, -1, 0};

// debug
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define DUMPA(a, n) cerr << #a << " = {" << a[0]; FOR(itr, 1, n) { cout << ", " << a[itr]; } cerr << "}" << endl;
#define DUMPAA(a, n, m) REP(itr, n) {REP(jtr, m) {cout << a[itr][jtr] << " ";} cout << endl;}

// template end

const int N_MAX = 10000;

const int DICE[7][4] =
{
    {},
    {2, 3, 5, 4},
    {6, 3, 1, 4},
    {2, 6, 5, 1},
    {2, 1, 5, 6},
    {1, 3, 6, 4},
    {5, 3, 2, 4},                    
};

int n;
string cmds[N_MAX];

void init()
{
}

void solve()
{
    int ans = 1;
    int top = 1;
    int front = 2;
    REP(i, n) {
        int east;
        REP(j, 4) if (DICE[top][j] == front) east = DICE[top][(j + 1) % 4];
        int west = 7 - east;
        int bottom = 7 - top;
        int back = 7 - front;
        if (cmds[i] == "North") {
            top = front;
            front = bottom;
        }
        if (cmds[i] == "East") {
            top = west;
        }
        if (cmds[i] == "West") {
            top = east;
        }
        if (cmds[i] == "South") {
            front = top;   
            top = back;            
        }
        if (cmds[i] == "Right") {
            front = east;
        }
        if (cmds[i] == "Left") {
            front = west;
        }
        ans += top;
    }
    cout << ans << endl;
}

int main()
{
    init();
    while (cin >> n, n) {
        REP(i, n) cin >> cmds[i];
        solve();        
    }
    return 0;
}
