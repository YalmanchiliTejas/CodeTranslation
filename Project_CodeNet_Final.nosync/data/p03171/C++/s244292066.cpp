#include<bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define SUM(v) accumulate(v.begin(),v.end(),lli(0))
#define rev(n,d) for(int i=n;i>=d;i--)
#define FOR0(n) for(int i=0;i<n;i++)
#define FOR(a,n) for(int i=a;i<n;i++)
#define FORQ(a,n) for(int i=a;i<=n;i++)
#define inf 10000000000000009
#define inff 0x3f3f3f3f
#define sz(a) int((a).size())
#define all(c) c.begin(), c.end()
#define ff first
#define ss second
#define endl "\n"
#define mod 1000000007
#define mem(ar,x) memset(ar,x,sizeof ar)
#define present(container, element) (container.find(element) != container.end())
#define max3(a,b,c) return (lli(a)>lli(b)?(lli(a)>lli(c)?a:c):(lli(b)>lli(c)?b:c))
#define max4(a,b,c,d) return (max3(a,b,c)>lli(d)?(max3(a,b,c)):d)
#define min3(a,b,c) return (lli(a)<lli(b)?(lli(a)<lli(c)?a:c):(lli(b)<lli(c)?b:c))
#define min4(a,b,c,d) return (max3(a,b,c)<lli(d)?(max3(a,b,c)):d)
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<int,pii>ppii;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<pii>vpii;
const int N=3005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
int main(){
	fast
	int n;
	cin>>n;
	lli a[n+4],sum=0;
	FOR0(n){
		cin>>a[i];
		sum+=a[i];
	}
//	dp[0][0]=0;
	lli dp[N+5][N+5];
	mem(dp,0);
//	FOR0(N+5){
//		for(int j=0;j<N+5;j++){
//			dp[i][j][0]=0;
//			dp[i][j][1]=-1*inf;
//		}
//	}
//	for(int i=1;i<=n;i++){
//		int pr=i%2;
//		int dpr=1-pr;
//		for(int j=i;j>=0;j--){
//			int bk=n-(i-j)+1;
//			if(pr==0)
//			dp[i][j][pr]=max(dp[i-1][j-1][dpr]+a[j],dp[i-1][j][dpr]+a[bk]);
//			else
//			dp[i][j][dpr]=min(dp[i-1][j-1][pr]-a[j],dp[i-1][j][pr]-a[bk]);
//		}
//	}
//	lli ans=0;
//	if(n%2==0){
//		FOR0(n+1){
//			ans=max(ans,dp[n][i][0]);
//		}
//		cout<<ans;
//		return 0;
//	}
//	ans=-1*inf;
//	FOR0(n+1){
//			ans=min(ans,dp[n][i][1]);
//		}
//		cout<<ans;
	for(int i=n-1;i>=0;i--){
		for(int j=i;j<n;j++){
			if(i==j) dp[i][j]=a[i];
			else dp[i][j]=max(-dp[i+1][j]+a[i],-dp[i][j-1]+a[j]);
		}
	}
	cout<<dp[0][n-1];
}

