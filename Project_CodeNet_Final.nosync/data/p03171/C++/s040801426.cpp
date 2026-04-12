#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define pb push_back
typedef vector<int> vi;
#define mod 1000000007
#define maxn 3005
int n;
vi a(maxn);
int dp[maxn][maxn];
int removal_game(int i,int j)
{if(i>j)
return 0;
if(dp[i][j]!=-1)
return dp[i][j];
if(i==j)
return dp[i][j]=a[i];
if(i==j-1)
return dp[i][j]=max(a[i],a[j]);
return dp[i][j]=max(a[i]+min(removal_game(i+2,j),removal_game(i+1,j-1)),a[j]+min(removal_game(i,j-2),removal_game(i+1,j-1)));
}
int32_t main() {
    int s=0;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i],s+=a[i];
    cout<<2*max(a[0]+min(removal_game(2,n-1),removal_game(1,n-2)),a[n-1]+min(removal_game(0,n-3),removal_game(1,n-2)))-s;
    return 0;
}
