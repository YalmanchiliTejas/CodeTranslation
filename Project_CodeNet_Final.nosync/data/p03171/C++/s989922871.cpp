#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define vec vector<int,int> 
#define int long long 
#define pii pair<int,int>
int visited[100001];

//int ax,ay,bx,by,t_x0,t_y0;
int dp[3001][3001];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	
	int t=1;
	//cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int sum=0;
		rep(i,n){
			cin>>arr[i];
			sum+=arr[i];
		}
		//sort(arr,arr+n);
		for(int i=0;i<n;i++){
			dp[i][i]=arr[i];
		}
		for(int i=0;i<n-1;i++){
			dp[i][i+1]=max(arr[i],arr[i+1]);
		}
		int a=2;
		while(1){
			if(a>=n) break;
			for(int i=0;i<n-a;i++){
				int j=i+a;
				dp[i][i+a]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),arr[j]+min(dp[i+1][j-1],dp[i][j-2]));
			}
			a++;
		}
		cout<<(2*dp[0][n-1]-sum)<<endl;
	}
	//exit();
	return 0;
}
