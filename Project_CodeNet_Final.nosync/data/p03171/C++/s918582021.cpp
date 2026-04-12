/*
  Reference:-
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forn1(i, n) for (int i = 1; i < int(n); i++)
#define PI pair<int,int>
#define all(vec) vec.begin(),vec.end()
ll mod=1000000007;
ll ar[3005];
ll dp[3005][3005];
int in[3005][3005];
ll x,y;
ll cnt=0;
int n;
ll solve(int i,int j,int fl){
    if(i>j){
        dp[i][j]=0;
        in[i][j]=n;
        return dp[i][j];
    }
    cnt++;
    if(dp[i][j])return dp[i][j];
    int x1=0,y1=0;
    if(fl==0){
        if(solve(i+1,j,1)>solve(i,j-1,1)){
            //x1+=ar[j]+dp[i][j-1];
            in[i][j]=j;
            dp[i][j]=ar[j];
            if(in[i][j-1]==i)dp[i][j]+=solve(i+1,j-1,1);
            else dp[i][j]+=solve(i,j-2,1);
            //x+=x1;
        }
        else{
            //x1+=ar[i]+dp[i+1][j];
            in[i][j]=i;
            dp[i][j]=ar[i];
            if(in[i+1][j]==i+1)dp[i][j]+=solve(i+2,j,1);
            else dp[i][j]+=solve(i+1,j-1,1);
        }
        //dp[i][j]=x1;
    }
    else {
        if(solve(i+1,j,0)>solve(i,j-1,0)){
            //y1+=ar[j]+dp[i][j-1];
            in[i][j]=j;
            dp[i][j]=ar[j];
            if(in[i][j-1]==i)dp[i][j]+=solve(i+1,j-1,0);
            else dp[i][j]+=solve(i,j-2,0);
            //y+=y1;
        }
        else {
            //y1+=ar[i]+dp[i+1][j];
            in[i][j]=i;
            dp[i][j]=ar[i];
            if(in[i+1][j]==i+1)dp[i][j]+=solve(i+2,j,0);
            else dp[i][j]+=solve(i+1,j-1,0);
        }
        //dp[i][j]=y1;
    }
    return dp[i][j];
}
int main(){
    std::ios::sync_with_stdio(false);
    //string s1,s2;
    //int n;
    cin>>n;
    //ll ar[n];
    ll sum=0;
    forn(i,n){cin>>ar[i];sum+=ar[i];}ar[n]=0;
    ll ans=solve(0,n-1,0);
    //cout<<in[0][n-1]<<endl;
    int cnt=0;
    int i1=0,j1=n-1;
    if(in[i1][j1]==i1)i1++;
    else j1--;
    ans=ans-(sum-ans);
    cout<<ans;

    return 0;
}
/*
4
10 100 10 10
*/
