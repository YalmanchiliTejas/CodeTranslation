#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(v) v.begin(), v.end()
#define vl vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
const int N=100005;
ll dp[3003][3004]={};
void solve()
{
    int n,k=1,m=0,i=1,j,x,y,l,r,p,q,z,a[3000];
    ll ans=0;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    //Add sec subtract first
    for(i=n;i>0;i--)
    {
        for(j=i;j<=n;j++)
        {
            if(i==j) dp[i][j]=a[i];
            else
                dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    cout<<dp[1][n];
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif 
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}