#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec(k) vector<k>
#define vecvec(k) vector<vector<k> >
#define pai(k) pair<k,k>
#define mod 1000000007
#define mpai make_pair
#define p1 first
#define p2 second
#define umap(x,y) unordered_map<x,y>
ll dp[3001][3001];
ll solve(vector<ll>&arr, int n,int i, int j, bool turn)
{
	// this DP table is acctually for player 1 ..if the turn is 0 then player 2 turn will try to make player 1 total minimum.
	//

	if(i>j)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	if(turn==1)
 		dp[i][j]= max(arr[i]+solve(arr,n,i+1,j,0), arr[j]+solve(arr,n,i,j-1,0));// here arr[i] is added since it is pl1 turn
 	else
 		dp[i][j]=min(solve(arr,n,i+1,j,1), solve(arr,n,i,j-1,1)); // here arr[i] is not added since it will be added to score of player two but we are adding for player 1 only.

 	// else
 	// 	dp[i][j]=min(arr[i] +max(solve(arr,n,i+1,j-1,1),solve(arr,n,i+2,j,1)),
		// 				arr[j]  +max( solve(arr,n,i+1,j-1,1),solve(arr,n,i,j-2,1)));
 	return dp[i][j];

}
ll solveagain(vector<ll>&arr, int n,int i, int j)
{
	if(i>j)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	return dp[i][j]=max(arr[i]+ min(solveagain(arr,n,i+1,j-1), solveagain(arr,n,i+2,j)),
						 arr[j]+ min(solveagain(arr,n,i+1,j-1), solveagain(arr,n,i,j-2)));
}

int main()
{
ios_base:: sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);


    ll n,x,sum=0;
    cin>>n;
    vec(ll) arr;
    for(int i=0;i<n;i++){
	cin>>x;
	arr.push_back(x);
	sum+=x;
}
memset(dp,-1,sizeof(dp));
ll ans=solveagain(arr, n,0,n-1);

 // cout<<ans<<"\n";
cout<<(2*ans-sum)<<"\n";

return 0;
}
