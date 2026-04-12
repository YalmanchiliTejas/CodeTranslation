#include<bits/stdc++.h>
#define pb          push_back
#define endl        '\n'
#define pll         pair<int,int>
#define vll          vector<int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define int	    int64_t
#define ios     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
int n,i,j,k,l,sum=0,flag=0,ans=0,a[3001],v[101],m;
int dp[3005][3005][2];
int is[3005][3005][2];
int f(int i, int j,int turn){
	if(i>j)
		return 0;
	if(i==j)
		return (turn==1?a[i]:-a[i]);
	if(is[i][j][turn]!=-1)
		return dp[i][j][turn];
	is[i][j][turn]=1;
	if(turn){
		return dp[i][j][turn] = max(a[i]+f(i+1,j,turn^1), a[j]+f(i,j-1,turn^1));
	}else{
		return dp[i][j][turn] = min(-a[i]+f(i+1,j,turn^1), -a[j]+f(i,j-1,turn^1));
	}
}
void solve(){
	memset(is,-1,sizeof dp);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<f(0,n-1,1)<<endl;
}
signed main()
{
    ios
    int test = 1;
    //cin>>test;
    while(test--){
    	solve();
    }
    return 0;
}