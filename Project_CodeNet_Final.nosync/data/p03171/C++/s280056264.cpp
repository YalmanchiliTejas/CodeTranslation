#include <bits/stdc++.h>
using namespace std;
#define print printf("==================\n")
#define ll long long
#define pi acos(-1.0)
#define eps 1e-16
#define max3(a,b,c) max(a,max(b,c))
const ll INF = 1 << 30;
#define mod 1000000007
typedef pair<double, double  > payar;
typedef struct
{
    ll  x, y;
} point;
priority_queue<payar, vector<payar>,  greater<payar> > pq; ///accending
vector< pair<double,payar  > > vpp;
vector < payar >  vp;
int n, k;
ll ara[100005];
ll dp[3001][3001][3];
ll rec(int i,int j,int player=1)
{
    if(i>j)
        return 0;
    if(i>n)
        return 0;
    if(j<1)
        return 0 ;
    ll maxi =-1;
    ll maxi2=-1;
    if(dp[i][j][player] != -1)
        return dp[i][j][player];
    ll &ans = dp[i][j][player];
    if(player==1)
        ans=max(ara[i]+rec(i+1,j,2), ara[j]+rec(i,j-1,2));
    if(player==2)
        ans =min(-ara[j]+rec(i,j-1,1),-ara[i]+rec(i+1,j,1));
    return ans ;


}
int main()
{

    cin>>n;
    for(int i = 1 ; i<=n ; i++)
        cin>>ara[i];
    for(int i = 0 ; i<=n ; i++)
    {
        for(int j  = 0 ; j<=n ; j++)
        {

            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
            dp[i][j][2]=-1;
        }
    }
    cout<< rec(1,n,1);
    return 0 ;
}


