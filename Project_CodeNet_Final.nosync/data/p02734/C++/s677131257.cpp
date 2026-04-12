#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#define ll long long
#define lld double
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<pii, ll>
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define ppb pop_back
#define d0(x) cout<<x<<" "
#define d1(x) cout<<(x)<<"\n"
#define d2(x,y) cout<<x<<" "<<y<<"\n"
#define d3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl
#define d4(x,y,z,w) cout<<x<<" "<<y<<" "<<z<<" "<<w<<endl
#define d5(x,y,z,w,s) cout<<x<<" "<<y<<" "<<z<<" "<<w<<" "<<s<<endl
using namespace std;
const ll mod = 998244353;

ll dp[3001][3001];ll dp1[3001][3001];int N,S;int a[3001];
void solve(int t)
{
    cin>>N>>S;
    for(int i=1;i<=S;i++)
        for(int j=0;j<=N;j++)
        {
            dp[j][i]=0;
            dp1[j][i]=0;
        }
    //dp[0][0]=0;
    for(int i=1;i<=N;i++)
            cin>>a[i];

    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=S-a[i];j++)
        {
            dp[i][j+a[i]] = (dp[i][j+a[i]]+dp1[i-1][j])%mod;
        }
        dp[i][a[i]] = (dp[i][a[i]]+i)%mod;
        for(int j=0;j<=S;j++)
            dp1[i][j] = (dp[i][j]+dp1[i-1][j])%mod;
    }
    ll ans = 0;
    for(int i=1;i<=N;i++)
    {
        ans = (ans+dp[i][S]*(N-i+1))%mod;
    }
    cout<<ans<<"\n";


}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    for(int t=1;t<=T;t++)
        solve(t);
}
