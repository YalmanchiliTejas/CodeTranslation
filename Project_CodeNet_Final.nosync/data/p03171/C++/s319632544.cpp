#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INF ((10e9)+7)
#define pb push_back
int call(int i,int j,vector<int>&A,vector<vector<bool > >&vis,vector<vector<int > >& dp)
{
    if(i>j)
    {
        return 0;
    }
    if(vis[i][j]) return dp[i][j];
    vis[i][j]=true;
    
    return dp[i][j]=max(A[i]-call(i+1,j,A,vis,dp),A[j]-call(i,j-1,A,vis,dp));
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<vector<int > >dp(N,vector<int > (N));
    vector<vector<bool > >vis(N,vector<bool >(N,false) );
    
    vector<int> A(N);
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    
    cout<<call(0,N-1,A,vis,dp);
    
    return 0;
    
}