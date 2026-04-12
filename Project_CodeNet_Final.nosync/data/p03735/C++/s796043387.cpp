
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

typedef pair<LL,LL> PLL;
const LL inf = 1e18 + 1e9;

int main()
{
    /* #ifndef ONLINE_JUDGE */
    /*     freopen("foo", "rt", stdin); */
    /* #endif */
    int N;
    while (cin >> N) {
        vector<PLL> A;
        multiset<LL> X,Y;
        FOR(i,0,N) {
            LL x,y; cin >> x >> y;
            if (x > y)
                swap(x,y);
            A.push_back(PLL(x,y)); X.insert(x); Y.insert(y);
        }
        sort(ALL(A));
        LL ans = inf;
        const LL rmin = *X.begin(),  bmax = *Y.rbegin();
        const LL rmax = *X.rbegin(), bmin = *Y.begin();
        const LL res = (rmax-rmin) * (bmax-bmin);
        ans = min(ans,res);
        FOR(i,0,N) {
            const LL x = A[i].first;
            const LL y = A[i].second;
            X.erase(X.find(x)); Y.insert(x);
            Y.erase(Y.find(y)); X.insert(y);
            const LL rmin = *Y.rbegin(), rmax = *Y.begin();
            const LL bmin = *X.rbegin(), bmax = *X.begin();
            const LL res = (rmax-rmin) * (bmax-bmin);
            ans = min(ans,res);
        }
        cout << ans << endl;
    }
    return 0;
}
