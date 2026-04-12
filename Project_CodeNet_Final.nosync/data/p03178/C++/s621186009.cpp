//R<3S
#include <bits/stdc++.h>
#define hell 1000000007
#define PI 3.14159265358979323844
#define mp make_pair
#define pb push_back
#define fi first 
#define se second
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))  
#define REVERSE(v) reverse(ALL(v))
#define endl "\n"
#define vecmax(v) max_element(all(v))
#define vecmin(v) min_element(all(v))
#define GCD(m,n) __gcd(m,n)
#define LCM(m,n) m*(n/GCD(m,n))
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(x) for(auto i : x)
#define sz(a) (int)a.size()
#define sl(a) (int)a.length()
#define int long long
#define ld long double 
#define pii std::pair<int, int> 
#define pll std::pair<ll, ll>  
#define vi vector<int>  
#define vl vector<ll>
#define vvi vector<vi > 
#define vii vector<pii >
#define mii map<int,int>
#define mll map<ll,ll>


using namespace std;
string s;
vi k;
int d,n;
int dp[10005][2][101];
int find(int i,int flag,int mod)
{
	if(i==n)
	{
		if(mod==0)return 1;
		return 0;
	}
	if(dp[i][flag][mod]!=-1)return dp[i][flag][mod];
	int limit;
	if(flag==0)limit=k[i];
	else limit=9;
	int sum=0,check=0;
	rep(j,limit+1)
	{
		check=0;
		if(j<k[i])check=1;
		sum+=find(i+1,check|flag,(mod+j)%d);
		sum%=hell;
	}
	return dp[i][flag][mod]=sum%hell;
	
}
void solve()
  {

	cin>>s>>d;
	rep(i,sz(s))k.pb(s[i]-'0');
	n=k.size();
	rep(i,10005)rep(j,2)rep(kk,101)dp[i][j][kk]=-1;
	int i=0,mod=0,flag=0;
	cout<<(find(i,flag,mod)-1+hell)%hell;

  }



signed main()
{
   std::ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int t;
   t=1;
   //cin>>t;
   while(t--)
    {
        solve();
    }


   return 0;
}
