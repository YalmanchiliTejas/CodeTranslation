#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
#define MOD 1000000007
#define INF 1000000000
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
#define endl '\n'
#define pl cout<<endl;
#define tc int t;cin>>t;while(t--)
#define get cin>>
#define geta ll a[n];for (int i = 0; i < n; ++i){cin>>a[i];}
#define puta for (int i = 0; i < n; ++i){cout<<a[i];}
#define put cout<<
ll maxi=LLONG_MIN;
ll mini=LLONG_MAX;
void fast() { ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL); }
ll dp[3005][3005];
int main() 
{
    fast();
    memset(dp,0,sizeof(dp));
    int n;
	cin>>n;
	vector<ll> a(n+1);
	for(int i=1;i<=n;++i)
	{
	cin>>a[i];
	}
	for(int i=n;i>=1;--i) 
	{
	dp[i][i] = a[i];
	for(int j=i+1;j<=n;++j)
	{
	dp[i][j] = max(a[j]-dp[i][j-1],a[i]-dp[i+1][j]);
	}
	}
	cout<<dp[1][n];
	return 0;
}
// dp1[i][j] =maximum score the first one to make
//  	the move can obtain by using a[i] to a[j]
// dp2[i][j] =maximum score the 2nd one to make
//  	the move can obtain by using a[i] to a[j]

// dp1[i][i] for all i from 1 to n is a[i]
// dp2[i][i] = 0

// dp1[i][j]=max(a[i]+dp2[i+1][j],a[j]+dp2[i][j-1])
// if(a[i]+dp2[i+1][j]>a[j]+dp2[i][j-1])
// {
// 	dp2[i][j]=dp1[i+1][j];
// }
// else
// {
// 	dp2[i][j]=dp1[i][j-1];
// }

// What if dp1[i+1][j]>a[i]+dp2[i+1][j] and a[i]+dp2[i+1][j]>a[j]+dp2[i][j-1] 
// 	and a[j]+dp2[i][j-1]>dp1[i][j-1]