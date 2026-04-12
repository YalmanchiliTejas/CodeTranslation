#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <utility>
#include <chrono>
#include <sstream>
#include <iomanip>
using namespace std;
#define MOD          1000000007
#define PI           3.14159265358979
#define OUT(x)       cerr << #x << " = " << x << endl; 
#define rep(i, n)    for (int (i) = 0; (i) < (int)(n); (i)++)
#define rer(i, l, r) for (int (i) = (int)(l); (i) <= (int)(r); (i)++)
#define reu(i, l, r) for (int (i) = (int)(l); (i) < (int)(r); (i)++)
#define each(i, v)   for (auto i : v)
#define all(x)       (x).begin(), (x).end()
#define rall(x)      (x).rbegin(), (x).rend()
#define pb(x)        push_back(x)
#define mp(x, y)     make_pair((x), (y))
#define fi           first
#define se           second
#define setp(x)      setprecision(x)
#define mset(m, v)   memset(m, v, sizeof(m))
//#define int          long long
//static const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
static const int INF =        0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef long long             ll;
typedef vector<int>           vi;
typedef vector<double>        vd;
typedef vector<long long>     vll;
typedef vector<string>        vs;
typedef vector<bool>          vb;
typedef pair<int, int>        pii;
typedef pair<long, long>      pll;
typedef vector<pii>           vpii;
typedef vector<pll>           vpll;
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }

int n;
vi g[101010];
bool matched[101010];

void dfs(int v, int prev) {
        rep(i, g[v].size()) if (g[v][i] != prev) dfs(g[v][i], v);
        if (prev != -1 && !matched[v] && !matched[prev]) matched[v] = matched[prev] = 1;
        return;
}

int main() { 
        cin >> n;
        rep(i, n - 1) {
                int a, b;
                cin >> a >> b;
                a --;
                b --;
                g[a].pb(b);
                g[b].pb(a);
        }
        dfs(0, -1);
        bool f = false;
        rep(i, n) if (!matched[i]) f = true;
        puts(f ? "First" : "Second");
        return 0;
}

