#include <bits/stdc++.h>
using namespace std;
#define printint(v) copy(begin(v), end(v), ostream_iterator<int>(cout," "))
#define printintv(s,e) copy(s,e, ostream_iterator<int>(cout," "))
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define clz(a) __builtin_clz(a) // cnt leading zeroes
#define ctz(a) __builtin_ctz(a) // cnt trailing zeroes
#define popc(a) __builtin_popcnt(a) // cnt set bits (for ints only diff for ll)
//https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html for other in built
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef pair<int,int> p32; 
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
#pragma GCC optimize ("-O2")
const int LIM = 5e5+5, MOD = 1e9+7;
ll t,n,m,k,x,y;

//string dp[55];

ll len[50];
ll cnt[50];

ll solve(int n,ll x)
{
	if(n==0 && x==1)
		return 1;
	if(x==0)
		return 0;
	else
	{
		ll half=len[n-1];
		//ll ret=0;
		if(x<= half+1)
		{
			return solve(n-1,x-1);
		}
		else if(x== half+2 )
			return cnt[n-1]+1;
		else if(x <= 2*half + 2)
		{
			return cnt[n-1]+1+solve(n-1,x-half-2);
		}
		else
			return cnt[n];
	}
}

int main()
{
	IOS;
	cin>>n>>x;
	len[0]=1;
	for(int i=1;i<=n;i++)
	{
		len[i]=2*len[i-1]+3;
	}
	cnt[0]=1;
	for(int i=1;i<=n;i++)
		cnt[i]=2*cnt[i-1] + 1;
	//ll ans=0;
	//ans=solve(n,x);
/*	dp[0]="P";
	for(int i=1;i<=n;i++)
	{
		dp[i]="B"+dp[i-1]+"P"+dp[i-1]+"B";
	}
	reverse(dp[n].begin(),dp[n].end());
	ll ans=0;
	forn(i,x){
		ans+=(dp[n][i]=='P');
	}
	cout<<ans;*/
	//cout<<len[n];
	cout<<solve(n,x);
}