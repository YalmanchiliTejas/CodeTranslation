#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std; 
#define int      long long int
#define MOD      1000000007
#define pb       push_back
#define pf		 push_front
#define vi       vector<int>
#define mi  	 map<int,int>
#define umi		 unordered_map<int,int>
#define pii      pair<int,int>
#define ff 		 first
#define ss 		 second
#define inf		 1e18
#define case	int t;cin>>t;while(t--)	
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void pre()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int32_t main()
	{pre();
	 //case
	 {int n;
	  cin>>n;
	  int dp[n][n],a[n];
	  for(int i=0;i<n;i++)
	  	cin>>a[i];
	  for(int j=0;j<n;j++)
	  	{for(int i=j;i>=0;i--)
	  		{if(i==j)
	  			dp[i][i]=a[i];
	  		 else
	  		 	dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);	
	  		}
	  	}
	  cout<<dp[0][n-1];		

	 }
 		return 0;
	}