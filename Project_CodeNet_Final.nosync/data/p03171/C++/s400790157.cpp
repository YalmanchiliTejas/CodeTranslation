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
int n,k;
int a[3005];
int dp[3005][3005][2];
int find(int i,int j,int turn)
{
	if(j<i)return 0;
	if(dp[i][j][turn]!=-1)return dp[i][j][turn];
	if(turn==0)
	{
		return dp[i][j][turn]=max(a[i]+find(i+1,j,1-turn),a[j]+find(i,j-1,1-turn));
	}
	else
	return dp[i][j][turn]=min(find(i+1,j,1-turn)-a[i],find(i,j-1,1-turn)-a[j]);
	
}
void solve()
  {

	cin>>n;
	rep(i,3005)rep(j,3005)
	{dp[i][j][0]=-1;dp[i][j][1]=-1;}
	rep(i,n)cin>>a[i];
	cout<<find(0,n-1,0);

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
