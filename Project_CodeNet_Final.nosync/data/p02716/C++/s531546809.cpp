#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define endl "\n"
#define pii pair<int,int> 
#define ff first
#define ss second
#define mii map<int,int>
#define si set<int>
#define sti stack<int>
#define qi queue<int>
#define vi vector<int>
#define pq priority_queue<int>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int M=1e9+7;
const int N=2e5+5;
const int N1=-1e18-5;
int dp[N][3];
int a[N];
 
int func(int x,int y,int n,int flag=0){
	if(x>=n||y<0) return 0;
	if(dp[x][y]!=N1) return(dp[x][y]);
	if(flag==0&&x==n-1) return(N1);
	int res=N1;
	for(int i=0;i<=y;i++){
		res=max(res,a[x+i]+func(x+i+2,y-i,n,((flag==1)||(i>0)))); 
	}
	return(dp[x][y]=res);
}
 
int32_t main(){
    IOS;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
    	for(int j=0;j<3;j++) dp[i][j]=N1;
    }
	int ans=func(0,n%2+1,n);
	cout<<ans<<endl;
}