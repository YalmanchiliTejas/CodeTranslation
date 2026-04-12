#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define mp make_pair
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
const int N=3e3+5;
int dp[N][N];
int a[N],n;

int find(int x,int y){
	if(dp[x][y]!=-1e18){return(dp[x][y]);}
	if(x+y>=n) return(0);
	int st=x;
	int la=n-y-1;
	dp[x][y]=max(dp[x][y],a[st]-find(x+1,y));
	dp[x][y]=max(dp[x][y],a[la]-find(x,y+1));
	return(dp[x][y]);
}

int32_t main(){
    IOS;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<N;i++){
    	for(int j=0;j<N;j++) dp[i][j]=-1e18;
    }
	cout<<find(0,0);
}