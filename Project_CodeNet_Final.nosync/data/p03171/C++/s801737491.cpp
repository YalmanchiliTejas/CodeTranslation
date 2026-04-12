#include<bits/stdc++.h>
using namespace std;
#define w(t) int t;cin>>t;while(t--)
#define pb   push_back
#define mk   make_pair
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
typedef long long ll;
const ll mod=1e9+7;
ll dp[3001][3001];

ll solve(vector<int>&v,int i,int j,bool turn){
	if(i>j)
		return 0;
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	if(turn ==1)
		return dp[i][j]=max(v[i]+solve(v,i+1,j,0),v[j]+solve(v,i,j-1,0));
	else
		return dp[i][j]=min(solve(v,i+1,j,1),solve(v,i,j-1,1));
}
int main()
{

	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
    
    memset(dp,-1,sizeof dp);
    int n;cin>>n;
    ll sum=0;
    vector<int>A(n+1);
    for(int i=1;i<=n;i++){
    	cin>>A[i];
    	sum+=A[i];
    }
    ll scoreX=solve(A,1,n,1);
    ll scoreY=sum-scoreX;
    cout<<scoreX-scoreY;
    return 0; 
}

/*
here player 1 want to miximum the score where as player two wants to minimum the score of player 1
that's why
if turn ==1
dp[i][j]=max(v[i]+solve(A,i+1,j,0),v[j]+solve(A,i,j-1,0)) // here i can take either from first or last

if the turn is player two then it wants to minimum the score of player 1
dp[i][j]=min(solve(A,i+1,j,1),solve(A,i,j-1,1))


*/