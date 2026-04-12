#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
#define t1(x)             cerr<<#x<<"="<<x<<endl
#define t2(x, y)          cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define t3(x, y, z)       cerr<<#x<<"=" <<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define t4(a,b,c,d)       cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl
#define t5(a,b,c,d,e)     cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl
#define t6(a,b,c,d,e,f)   cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<" "<<#f<<"="<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define fastio() ios::sync_with_stdio(0);cin.tie(0)
#define MEMS(x,t) memset(x,t,sizeof(x));
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define MOD 998244353
#define endl "\n" 
#define int long long
#define inf 1e18
#define ld long double
/*-------------------------------------------------------------------------------------------------------------------------------------*/
int n,s;
const int N=3005;
int dp[N][N];
int ar[N];

int rec(int ind,int done)
{
	if(done>s)
		return 0;
	if(done==s)
	{
		return n-(ind-1)+1;
	}
	if(ind>n)return 0;
	int &ans=dp[ind][done];
	if(ans>=0)return ans;

	ans=rec(ind+1,done)+rec(ind+1,done+ar[ind]);
	ans%=MOD;
	return ans;
}
int32_t main()
{
	fastio();
	memset(dp,-1,sizeof(dp));
	cin>>n;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=rec(i,0);
		ans%=MOD;
	}
	cout<<ans<<endl;
}
