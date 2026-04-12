#include <bits/stdc++.h>
#define _boost ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define fi first
#define se second
#define clz __builtin_clz
#define clzll __builtin_clzll
#define bp __builtin_popcount
#define _unique(x) sort((x).begin(),(x).end()),(x).erase(unique((x).begin(), (x).end()),(x.end()))
#define all(x) (x).begin(),(x).end()
#define _rand(i,j) uniform_int_distribution<int>(i, j)(rng___)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;
typedef pair < LD, LD > PDD;
template < typename _T, typename _T2> string to_string(pair<_T,_T2> x) {return "<"+to_string(x.fi)+", "+to_string(x.se)+">";}
template < typename _T> string to_string(vector<_T> vec) {string s="[ "; for(auto el:vec)s+=to_string(el)+", "; s[s.size()-1]=']';s[s.size()-2]=' '; return s;}
string to_string(string s) {return s;}
template < typename _T> string to_string(set<_T> vec) {string s="{ "; for(auto el:vec)s+=to_string(el)+", "; s[s.size()-1]='}';s[s.size()-2]=' '; return s;}
template < typename _T, typename _T2> string to_string(map<_T,_T2> vec) {string s="{ "; for(auto el:vec)s+="mp["+to_string(el.fi)+"]= "+to_string(el.se)+", "; s[s.size()-1]='}';s[s.size()-2]=' '; return s;}
template < typename _T > inline void _DBG(const char *s, _T x){cerr << s << " = " << to_string(x) << "\n";}
template < typename _T, typename... args > void _DBG(const char *s, _T x, args... a){while(*s != ',') cerr << *s++;cerr << " = " << to_string(x) << "\n";_DBG(s + 1, a...);}
#ifdef LOCAL
#define _print(...) _DBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define _print(...) ;//cout<<2;//(__VA_ARGS__)
#endif
mt19937 rng___(chrono::steady_clock::now().time_since_epoch().count());


const LL MOD = 1e9+7;//998244353;
const LL LLINF = 1e18+7;
const int N=1e5+8;


int main()
{
    _boost;
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    vector<vector<LL>> dp(n,vector<LL>(n,0));
    for(int i=0;i<n;i++)dp[i][i]=vec[i];
    for(int d=1;d<n;d++)
    {
        for(int i=0;i<n;i++)
        {
            if(i+d>=n) continue;
            dp[i][i+d]=max(-dp[i][i+d-1]+vec[i+d],-dp[i+1][i+d]+vec[i]);
        }
    }
    cout<<dp[0][n-1];
}


