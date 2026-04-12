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

// std::ios::sync_with_stdio(false);

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

const int maxv = 1e5+5;
int vis[maxv];
vector<int> G[maxv];

int main()
{
/* #ifndef ONLINE_JUDGE */
/*     freopen("foo", "rt", stdin); */
/* #endif */
    int N;
    while (cin >> N) {
        memset(vis,0,sizeof(vis));
        FOR(i,1,N+1)
            G[i].clear();
        FOR(_,0,N-1) {
            int u,v; cin >> u >> v;
            G[u].push_back(v); G[v].push_back(u);
        }
        queue<int> Q; Q.push(1); vis[1]++;
        stack<int> S;
        while (Q.size()) {
            const int u = Q.front(); Q.pop(); S.push(u);
            FOR_ALL(v,G[u]) if (!vis[*v]) {
                Q.push(*v); vis[*v]++;
            }
        }
        memset(vis,0,sizeof(vis));
        string ans = "Second";
        while (S.size() && ans != "First") {
            const int u = S.top(); S.pop();
            if (!vis[u]) {
                int i = 0; const int n = G[u].size();
                for (; i < n; i++) {
                    const int v = G[u][i];
                    if (!vis[v]) {
                        vis[v]++; break;
                    }
                }
                if (i == n)
                    ans = "First";
                vis[u]++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
