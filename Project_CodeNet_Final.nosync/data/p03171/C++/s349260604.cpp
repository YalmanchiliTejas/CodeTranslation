
// Problem : L - Deque dp on partial games
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_l
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
 #define int               long long
#define nl                "\n"
#define pb                push_back
#define mp                make_pair
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define f                 first
#define s                 second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define fast_io           ios_base::sync_with_stdio(false);cin.tie(NULL);
 
const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

 
 int dp[3000][3000][2];
 //dp[L][R][P] l,r for segments left both inclusive , pth player turn
 //p=0 first,p=1 second;



void solve(){
	int n,sum=0;
	cin>>n;
	vector<int>v(n);
	for(int& a:v){cin>>a;sum+=a;}
	//cout<<sum<<nl;
     //base case
     rep(i,0,n)
    { dp[i][i][0]=v[i];
     dp[i][i][1]=0;}
     //transition state
     rep(rminusl,1,n)
       for(int l=0;l+rminusl<n;l++)
        {
        	int r=l+rminusl;
        	dp[l][r][0]=max(v[l]+dp[l+1][r][1],
        	                v[r]+dp[l][r-1][1]);
        	dp[l][r][1]=min(dp[l+1][r][0],
        	                dp[l][r-1][0]);
        	                

        }
       
     //ans
     
     int x=dp[0][n-1][0];
    // cout<<x<<nl;
	 cout<<(2*x)-sum;

}	


signed main(){
	fast_io
   
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}
