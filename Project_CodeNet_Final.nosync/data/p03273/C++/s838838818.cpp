#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
//#include <regex>

/* g++ -g -std=c++0x */
/* g++ -g -std=c++11 */

using namespace std;

// freopen("input.txt", "rt", stdin);
// freopen("output.txt", "wt", stdout);

#define ALL(c)          (c).begin(), (c).end()
#define ALLR(c)         (c).rbegin(), (c).rend()
#define FOR(i,a,b)      for (int i=(a); i < (b); ++i)
#define FORR(i,a,b)     for (int i=(a); i > (b); --i)
#define FOR_ALL(i,c)    for (__typeof((c).begin()) i=(c).begin();   \
                             i != (c).end(); ++i)
#define FOR_ALLR(i,c)   for (__typeof((c).rbegin()) i=(c).rbegin(); \
                             i != (c).rend(); ++i)
#define SZ(array)       (sizeof(array)/sizeof(array[0]))
#define lc(x)           (x<<1)     /* 2*x */
#define rc(x)           (x<<1 | 1) /* 2*x+1 */
#define lowbit(x)       (x & (-x)) /* 0b10100 -> 0b100 */

typedef long long       LL;
typedef map<int,int>    MII;
typedef pair<int,int>   PII;
typedef set<int>        SI;
typedef vector<bool>    VB;
typedef vector<double>  VD;
typedef vector<int>     VI;
typedef vector<string>  VS;

/* check if a key is in container C */
template <class C>
inline bool in_(const typename C::key_type& k, const C& A)
{ return A.find(k) != A.end(); }
inline bool in_(const string& s, const string& S)
{ return S.find(s) != string::npos; }

const int maxn = 510;
char G[maxn][maxn];
int vis[maxn][maxn];

int main()
{
    int h,w;
    while (cin >> h >> w) {
        FOR(i,0,h) FOR(j,0,w)
            cin >> G[i][j];
        memset(vis,0,sizeof(vis));
        FOR(i,0,h) {
            bool good = true;
            FOR(j,0,w)
                good &= G[i][j] == '.' && !vis[i][j];
            if (good) {
                FOR(j,0,w)
                    vis[i][j]++;
            }
        }
        FOR(j,0,w) {
            bool good = true;
            FOR(i,0,h)
                good &= G[i][j] == '.' || vis[i][j];
            if (good) {
                FOR(i,0,h)
                    vis[i][j]++;
            }
        }
        int cnt = 0;
        FOR(i,0,h) FOR(j,0,w) if (vis[i][j])
            cnt++;
        if (cnt == h*w)
            cout << endl;
        else {
            FOR(i,0,h) {
                int cnt = 0;
                FOR(j,0,w) if (!vis[i][j]) {
                    cout << G[i][j];
                    cnt++;
                }
                if (cnt)
                    cout << endl;
            }
        }
    }
    return 0;
}
