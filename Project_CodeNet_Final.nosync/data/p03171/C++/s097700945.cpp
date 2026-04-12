#include<bits/stdc++.h> 
using namespace std;
#define se second
#define fr first
#define int long long int
#define pb push_back
#define inf 1e18
#define all(v) v.begin(),v.end()
#define CHAL_BAAP_KO_MT_SIKHA ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
/*
    Damn Fast:TheFuckinMastermind
    while(How to solve the Question?){
                Read the Question Again!!
           }
        do
            Practise
    #Motivation::::0/0  
*/
const int N=4e3;
int dp[N+1][N+1];
int n,a[N+1];
int solve(int i,int j){
    if(i>n or j<=0){
        return 0;
    }
    if(j<i)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans1=a[i]+min(solve(i+2,j),solve(i+1,j-1));
    int ans2=a[j]+min(solve(i+1,j-1),solve(i,j-2));
    return dp[i][j]=max(ans1,ans2);
}
signed main()
{
   
    CHAL_BAAP_KO_MT_SIKHA
    cin>>n; 
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    memset(dp,-1,sizeof(dp));
    int x=solve(1,n);
    int y=sum-x;
    cout<<x-y<<endl;
}