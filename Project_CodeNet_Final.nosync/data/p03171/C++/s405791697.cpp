#include<bits/stdc++.h>
#define crap ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
#define int ll

using namespace std;

const int N = 3005;
int A[N];
int dp[N][N][2];
int n;


int solve(int start,int end,int turn){
	if(start==end) return A[start];
	if(start>end) return 0;

   if(dp[start][end][turn]!=-1) return dp[start][end][turn];

   return dp[start][end][turn] = max(A[start] - solve(start+1,end,1^turn), A[end] - solve(start,end-1,1^turn));


}

int32_t main()
{
   
    crap;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];

    int ans = solve(0,n-1,0);
	cout<<ans<<endl;

}