
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

struct Edge {
    int u,v,c;
    Edge(const int u, const int v, const int c)
    : u(u),v(v),c(c) {}
    bool operator<(const Edge& rhs) const
    { return c < rhs.c; }
};

const int maxv = 1e5+5;
int uf[maxv], N;

int find(const int x)
{
    if (x != uf[x])
        uf[x] = find(uf[x]);    /* pass compression */
    return uf[x];
}

void unin(const int x, const int y)
{ const int a = find(x), b = find(y); uf[b] = a; }

int main()
{
/* #ifndef ONLINE_JUDGE */
/*     freopen("foo", "rt", stdin); */
/* #endif */
    while (cin >> N) {
        vector<PII> A(N);
        FOR(i,0,N)
            cin >> A[i].first >> A[i].second;
        set<PII> S(ALL(A)); map<PII,int> V;
        int cnt = 1;
        FOR_ALL(i,S) {
            const int v = cnt++;
            V[*i] = v; uf[v] = v;
        }
        vector<Edge> E;
        PII pre(-1,-1);
        FOR_ALL(i,V) {
            if (pre != PII(-1,-1)) {
                const int u = V[pre];
                const int v = i->second;
                const int c = i->first.first - pre.first;
                E.push_back(Edge(u,v,c));
            }
            pre = i->first;
        }
        vector<PII> B;
        FOR_ALL(i,S)
            B.push_back(PII(i->second,i->first));
        sort(ALL(B));
        pre = PII(-1,-1);
        FOR_ALL(i,B) {
            const PII p = PII(i->second,i->first);
            if (pre != PII(-1,-1)) {
                const int u = V[pre];
                const int v = V[p];
                const int c = p.second - pre.second;
                E.push_back(Edge(u,v,c));
            }
            pre = p;
        }
        sort(ALL(E));
        LL ans = 0;
        FOR_ALL(i,E) {
            const int a = find(i->u);
            const int b = find(i->v);
            if (a != b) {
                ans += i->c;
                unin(i->u,i->v);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
