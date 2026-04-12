#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mkp make_pair
#define rep(i,s,f) for(i=s;i<f;i++)
#define db cout<<'h'<<'i'<<endl 
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define vi vector<int>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define PI 3.14159265
#define mod 1000000007
#define mod2 998244353
#define space 100005
#define lg 18
//<<fixed << setprecision(9)

int main()
{
    int n,i,j,t;
    boost;

    cin>>n;
    int arr[n];
    rep(i,0,n)cin>>arr[i];

    ll dp[n][n][2];//mx,mn

    int len;
    rep(len,1,n+1)
    {
        rep(i,0,n+1-len)
        {
            j=i+len-1;
            if(len==1)
            {
                dp[i][j][0]=arr[i];
                dp[i][j][1]=-arr[i];
            }
            else
            {
                dp[i][j][0]=max(dp[i+1][j][1]+arr[i],arr[j]+dp[i][j-1][1]);
                dp[i][j][1]=min(dp[i+1][j][0]-arr[i],-arr[j]+dp[i][j-1][0]);
            }
        }
    }
    cout<<dp[0][n-1][0];
    return 0;
}

