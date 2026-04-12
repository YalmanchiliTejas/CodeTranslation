#include<bits/stdc++.h>
#define ll long long int
#define db long double
#define ull unsigned long long int
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define Nmax 1000005
#define INF 1000000000
#define MOD 1000000007
#define MAXN 1000005
 
using namespace std;

ll dp[3001][3001];
ll a[3001];
ll n;

ll recur(ll i,ll j)
{
	if(i>j) return 0;
	if(i==j) return a[i];
	if(dp[i][j]!=-INF) return dp[i][j];
	ll sum1=0,sum2=0;
	sum1=recur(i+1,j);
	sum2=recur(i,j-1);
	return dp[i][j]=max(a[i]-sum1,a[j]-sum2);

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests=1;
    // cin>>tests;
    while(tests--)
    {	
    	ll i,j;
    	cin>>n;
    	rep(i,1,n) cin>>a[i];
    	rep(i,0,n)
    	{
    		rep(j,0,n)
    		dp[i][j]=-INF;
    	}
    	cout<<recur(1,n);
    }
    	return 0;
    
}