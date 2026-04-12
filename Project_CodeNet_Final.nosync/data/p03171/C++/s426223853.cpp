#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 27
#endif

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) (int)(v.size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ar array
#define forn(i, n) for(int i = 0; i < n ; ++i)
#define for1(i, n) for(int i = 1; i <=n ; ++i)
#define ford(i, n) for(int i = n-1; i>= 0;--i)
#define UNQ(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define mem(X,val) memset(X, val, sizeof((X)))

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>>  vvi ;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpi ;

const db PI = acos(-1);
const ll mod = 1e9+7;
template <class T>void smax(T& x,T y){ if(x<y)x=y;}
template <class T>void smin(T& x,T y){ if(x>y)x=y;}
template<typename T1, typename T2> T1 powz(T1 A, T2 B);
/***************************************************main code**************************************************************/
const int MXN=1e6+5;
const ll INF = 9e18+200;
const int inf = 1e9+100;
const int mxn = 2e5+20;

ll dp[3005][3005];
void test_case()
{	
	int n; cin >> n;
	vi a(n); forn(i, n) cin >> a[i];
	for(int L = n-1; L>=0;--L){
		for(int R = L ; R < n ; ++R){
			if(L == R)
				dp[L][R] = a[L];
			else	
			dp[L][R] = max(a[L] - dp[L+1][R],a[R]-dp[L][R-1]);
		}
	}
	cout << dp[0][n-1];
}
/*************----------------------------******************/
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef VIJY_DEFINE
    freopen("input.txt","r",stdin);
#endif
//  freopen("output.txt","w",stdout);
    int Tests = 1;
//  cin >> Tests;
    
    for(int tc = 1; tc <= Tests; ++tc){
        //cout <<"Case #"<<tc<<": ";
        test_case();
        cout<<'\n';
    }
#ifdef VIJY_DEFINE
    cerr << "Time elapsed: "<< 1.0*clock() / CLOCKS_PER_SEC <<"s.\n";
#endif   
}
template<typename T1, typename T2>
T1 powz(T1 X,T2 B)
{
    ll A = X;
    ll res=1;
        A%=mod; 
        assert(B>=0); 
    for( ; B ; B>>=1){
        if(B&1)res=res*A%mod;
        A= A*A%mod;
    }
    return res;
}
