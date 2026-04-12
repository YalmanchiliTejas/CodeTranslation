#include<bits/stdc++.h>
using namespace std;
#define int long long int 
#define pi pair<int,int> 
#define pb push_back
#define INF INT_MAX 
#define mod 1000000007ll
#define fi first
#define se second
#define f(i,p,q) for(int i=p;i<q;i++)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pii(a) printf("%d\n",a)
#define psi(a) printf(" %d",a)
#define poi(a) printf("%d",a)
#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld\n",a)
#define Nline() printf("\n")
#define sstr(str) scanf("%s",str)
#define pstr(str) printf("%s\n",str)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define vi vector<int>
#define vvi vector<vi>
#define all(v) (v).begin(),(v).end()
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v), greater<int>())
#define VI(a,n) vi a(n); rep(i,n)cin>>a[i];
#define sq(n) (n)*(n)
#define iso ios::sync_with_stdio(false); cin.tie(0);cout.tie(NULL);
signed main()
{    iso;
     int n;cin>>n;
	 int ar[n];
	 f(i,0,n)cin>>ar[i];
	 int dp[n+5][2];
	 dp[0][0]=0;
	 dp[0][1]=0;
	 dp[1][0]=ar[0];
	 dp[1][1]=ar[1];
	 for(int i=2;i<n;i++){
	 	if((i&1)==0){
	 		dp[i][1]=ar[i]+max(dp[i-2][1],dp[i-2][0]);
	 		dp[i][0]=max({dp[i-1][0],dp[i-1][1]});
		 }
		 else{
		 	dp[i][1]=max({dp[i-1][0]+ar[i],dp[i-2][1]+ar[i],dp[i-2][0]+ar[i]});
		 	dp[i][0]=(dp[i-2][0]+ar[i-1]);
		 }
	 }
	/* cout<<" ";
	 for(int i=1;i<n;i++){
	 	cout<<dp[i][1]<<" ";
	 }
	 cout<<"\n";cout<<" ";
	 for(int i=1;i<n;i++){
	 	cout<<dp[i][0]<<" ";
	 }
	 cout<<endl;*/
	 //cout<<dp[n-1][1]<<" "<<dp[n-1][0];
	 cout<<max(dp[n-1][1],dp[n-1][0]); 
}