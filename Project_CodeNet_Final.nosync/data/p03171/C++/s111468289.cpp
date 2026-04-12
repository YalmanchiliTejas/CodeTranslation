#include <bits/stdc++.h>     
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
#define int ll
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define VAR(v, i) __typeof( i) v=(i)
#define forit(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
 
using namespace std;
 
const int maxn = (int)3e3 + 100;
const int N = (int)1e5 + 100;
const int mod = (int)1e9 + 7;
 
#define inf mod
 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   
typedef vector<ll> Vll;               
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;
 
int n, a[maxn],s[2]={1,-1};
int dp[maxn][maxn][2];
int calc(int l,int r,int step){
	if(l==r)
		return a[l]*s[step];
	int &res=dp[l][r][step];
	if(res!=-1)
		return res;
	if(!step){
		res=-inf*inf;
		res=max(res,calc(l+1,r,step^1)+a[l]);
		res=max(res,calc(l,r-1,step^1)+a[r]);
	}else{
		res=inf*inf;
		res=min(res,calc(l+1,r,step^1)-a[l]);
		res=min(res,calc(l,r-1,step^1)-a[r]);
	}
	return res;
}
main () {
	cin>>n;
	forn(i,1,n)
		cin>>a[i];
	memset(dp,-1,sizeof(dp));
	cout<<calc(1,n,0);
}