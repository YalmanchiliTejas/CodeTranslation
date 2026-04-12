
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
/* #include <regex> */

using namespace std;

/* g++ -g -std=c++11 */

/* freopen("input.txt", "rt", stdin); */
/* freopen("output.txt", "wt", stdout); */

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

const LL inf = 1e16;
const int maxn = 2e5+5;
int L[maxn],R[maxn],A[maxn]; LL tree[2*maxn], mx[2*maxn];

void pushup(int i, const int n)
{
    for (; i > 0; i >>= 1) {
        mx[i] = max(mx[lc(i)], mx[rc(i)]);
    }
}

void pulldown(const int i)
{
    if (i) {
        pulldown(i>>1);
        tree[lc(i)] += tree[i]; mx[lc(i)] += tree[i];
        tree[rc(i)] += tree[i]; mx[rc(i)] += tree[i];
        tree[i] = 0;
    }
}

void add(int i, int j, const LL value, const int n)
{
    for (i += n, j += n; i < j; i >>= 1, j >>= 1) {
        if (i&1) {
            tree[i] += value; mx[i] += value;
            pulldown(i>>1); pushup(i>>1,n);
            i++;
        }
        if (j&1) {
            --j;
            tree[j] += value; mx[j] += value;
            pulldown(j>>1); pushup(j>>1,n);
        }
    }
}

LL query(int i, int j, const int n)
{
    LL ans = -inf;
    for (i += n, j += n; i < j; i >>= 1, j >>= 1) {
        if (i&1) {
            pulldown(i>>1); ans = max(ans, mx[i]); i++;
        }
        if (j&1) {
            j--; pulldown(j>>1); ans = max(ans, mx[j]);
        }
    }
    return ans;
}

bool cmp(const int& i, const int& j)
{ return R[i] > R[j]; }

int main()
{
#ifdef foo_
    freopen("foo", "rt", stdin);
#endif
    ios::sync_with_stdio(false);
    int n,m;
    while (cin >> n >> m) {
        memset(tree,0,sizeof(tree));
        memset(mx,0,sizeof(mx));
        vector<int> sorted;
        FOR(i,0,m) {
            cin >> L[i] >> R[i] >> A[i];
            sorted.push_back(i);
        }
        sort(ALL(sorted),cmp);
        const int size = n+5;
        /* int size = 1; */
        /* while (size <= n+1) */
        /*     size *= 2; */
        FOR(x,1,size) {
            while (sorted.size() && x > R[sorted.back()]) {
                const int i = sorted.back();
                add(L[i],R[i]+1,A[i],size);
                sorted.pop_back();
            }
            const LL best = query(0,x,size);
            add(x,x+1,best,size);
        }
        const LL ans = query(0,n+1,size);
        cout << ans << endl;
    }
    return 0;
}
