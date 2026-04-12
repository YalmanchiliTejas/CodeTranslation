#include <bits/stdc++.h>
#define lli long long int
#define vec2 vector<vector<lli>> 
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define FRE freopen("explicit.in","r",stdin);freopen("explicit.out","w",stdout)
#define mp make_pair
#define pll pair <lli,lli>
#define vll vector <lli>
#define pq2 priority_queue<pair<lli,lli>>
#define f first
#define s second
#define pb push_back
#define pf push_front
#define minii LLONG_MAX
#define ld long double 
const long double pi = 3.1415926535898;
#define dec greater<lli>()
//const lli mod=1000000007;
const lli mod=100000000;
using namespace std;

int main()
{
    fio;
    lli n;
    cin>>n;
    lli a[n+5];
    for (int i=1;i<=n;i++)
    cin>>a[i];
    lli dp[n+5][n+5];
    memset(dp,0,sizeof(dp));
    for (int i=n;i>=1;i--)
    {
        for (int j=i;j<=n;j++)
        {
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    cout<<dp[1][n];
    return 0;
}
