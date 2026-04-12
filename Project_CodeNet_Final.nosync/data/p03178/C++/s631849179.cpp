
#include <bits/stdc++.h>

using namespace std;

/* g++ -g -fsanitize=address -lasan -std=c++11 -Dfoo_ */

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

const int mod = 1e9+7;
const int maxk = 1e4+9;
const int maxd = 101;
int dp[maxk][maxd], digit[maxk];
string k; int d;

int dfs(const int i, const int j, const bool limit)
{
    if (i < 0)
        return j == 0;
    if (!limit && dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    int last = limit ? digit[i] : 9;
    FOR(x,0,last+1) {
        ans += dfs(i-1, (j+x)%d, limit && (x==last));
        ans %= mod;
    }
    if (!limit)
        dp[i][j] = ans;
    return ans;
}

int main()
{
#ifdef foo_
    freopen("foo", "rt", stdin);
#endif
    ios::sync_with_stdio(false);
    while (cin >> k >> d) {
        memset(dp,-1,sizeof(dp));
        int n = 0;
        FOR_ALLR(c,k)
            digit[n++] = *c-'0';
        const int ans = dfs(n-1,0,true);        
        cout << (ans-1+mod)%mod << endl;
    }
    return 0;
}
