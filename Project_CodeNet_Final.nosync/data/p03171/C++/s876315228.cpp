#include <bits/stdc++.h>

using namespace std;

//const int OO = 0x3f3f3f3f;
const long long OO = (long long) 1e18L+7;
//const unsigned long long UOO = (long long) 10e18+7;
#define lp(i,a,n) for(int i = a ; i < n ; ++i)
#define lpr(i,a,n) for(int i = a ; i >= n ; --i)
#define rep(i,vec) for(int i = 0 ; i < vec.size() ; ++i)
#define reprv(i,vec) for(int i = vec.size()-1; i >=0 ; --i)
#define eps (1e-5)
#define pb(i) push_back(i)
#define EPS 1e-9
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define debug(x) cout<<(#x)<<": \""<<x<<"\""<<endl
#define debugVec(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl

typedef vector<int> vi ;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef vector< pair<int,int> >  vpii;
typedef vector<pair<long long,long long>> vpll;
typedef vector<vector<int> > vvi ;
typedef complex<double> point;
typedef pair<ll,ll> pll;

ll  inv(ll a, ll b) {return 1 < a ? b - inv(b % a, a) * b / a : 1;}
ll  Pow(ll  B,ll  P){ll  R=1; while(P>0)  {if(P&1) R=(R*B);P/=2;B=(B*B);}return R;} //compute b^p
ll  GCD(ll  a,ll  b){ while(b){b ^= a ^=b ^= a %=b;}  return a;}
ll  LCM(ll  a,ll  b) { return (a / GCD(a,b)*b); }
ll  BigMod(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll )R;} //compute b^p%m
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//int i=uniform_int_distribution<int>(1,n)(rng);
///-----------------------------------------------------------------------------

int n;
vll nms;

ll dp[3002][30002];



///-----------------------------------------------------------------------------
int main()
{
    #ifndef ONLINE_JUDGE
//       freopen( "output.txt" , "w" , stdout ) ;
    //   freopen( "input.txt" , "r" , stdin ) ;
    auto stTime = clock();
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
//    cout.tie(0);
///-----------------------------------------------------------------------------------

    cin >> n ;
    nms.resize(n);
    lp(i,0,n) cin >> nms[i];

    lpr(l,n-1,0)lp(r,l,n){
        if(l==r) dp[l][r] = nms[l];
        else dp[l][r] = max( nms[l] - dp[l+1][r] , nms[r] - dp[l][r-1] );
    }

    cout << dp[0][n-1];



///------------------------------------------------------------------------------------
    #ifndef ONLINE_JUDGE
	cout << "\n\n\nExecution time: " <<
		(clock() - stTime) * 1e3 / CLOCKS_PER_SEC << " ms" << endl;
	#endif

    return 0;
}
