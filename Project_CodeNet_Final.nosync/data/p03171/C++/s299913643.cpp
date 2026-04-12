#include <bits/stdc++.h>

using namespace std;
#define int long long int
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define vi vector <int>
#define sz(s) (int)s.size()
#define pii pair<int,int>
#define piii pair< int,pair<int,int> >
#define tiii tuple <int,int,int>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rall(v) v.rbegin(),v.rend()
#define endl '\n'
#define matrix vector <vector <int> >
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define NAYAN freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define N 3006
#define mod 1000000007
#define mod2 998244353
#define inf 1e18

int dp[N][N][2];
int n;
int a[N];

int solve(int i,int j,int f)
{
    if(i>j)
        return 0;
    int &ans=dp[i][j][f];

    if(ans!=-1)
        return ans;

    int tmp;

    if(f==0)
    {
        tmp=max(a[i]+solve(i+1,j,1),a[j]+solve(i,j-1,1));
    }
    else
    {
        tmp=min(-a[i]+solve(i+1,j,0),-a[j]+solve(i,j-1,0));
    }
    ans=tmp;

    return ans;
}

int32_t main()  
{
    boost
    // #ifndef ONLINE_JUDGE 
    // NAYAN
    // #endif

  
    cin >> n;
    int i;
   
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
    }

    memset(dp,-1,sizeof dp);

    int ans=solve(1,n,0);

    cout << ans;




}