
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

/*
 * Greedy build the linear connections in horizontal and vertical
 * directions.
 */

const int maxv = 1e5+5;

struct Edge {
    int u,v,c;
    Edge(const int u, const int v, const int c)
    : u(u),v(v),c(c) {}
    bool operator<(const Edge& rhs) const
    { return c < rhs.c; }
};

struct Node {
    int x,y,v;
} A[maxv];

int uf[maxv], N;

int find(const int x)
{
    if (x != uf[x])
        uf[x] = find(uf[x]);    /* pass compression */
    return uf[x];
}

void unin(const int x, const int y)
{ const int a = find(x), b = find(y); uf[b] = a; }

bool cmp1(const Node& a, const Node& b)
{ return a.x < b.x; }

bool cmp2(const Node& a, const Node& b)
{ return a.y < b.y; }

int main()
{
/* #ifndef ONLINE_JUDGE */
/*     freopen("foo", "rt", stdin); */
/* #endif */
    while (cin >> N) {
        FOR(i,0,N) {
            cin >> A[i].x >> A[i].y; A[i].v = i; uf[i] = i;
        }
        vector<Edge> E;
        sort(A,A+N,cmp1);
        FOR(i,1,N) {            /* horizontal direction */
            const int u = A[i-1].v;
            const int v = A[i].v;
            const int c = A[i].x - A[i-1].x;
            E.push_back(Edge(u,v,c));
        }
        sort(A,A+N,cmp2);
        FOR(i,1,N) {            /* vertical direction */
            const int u = A[i-1].v;
            const int v = A[i].v;
            const int c = A[i].y - A[i-1].y;
            E.push_back(Edge(u,v,c));
        }
        sort(ALL(E));           /* Kruskal */
        LL ans = 0;
        FOR_ALL(i,E) {
            const int a = find(i->u);
            const int b = find(i->v);
            if (a != b) {
                ans += i->c; unin(a,b);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
