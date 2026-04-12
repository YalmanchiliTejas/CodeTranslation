#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3010,MOD=998244353;

int a[N],dp[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
            dp[i][j]=dp[i-1][j];
        dp[i][0]+=1;
        for(int j=s;j-a[i]>=0;j--)
            dp[i][j]+=dp[i][j-a[i]];
        for(int j=0;j<=s;j++)
            dp[i][j]%=MOD;
        ans+=dp[i][s];
//        for(int j=0;j<=s;j++)
//            cout<<dp[i][j]<<" ";
//        cout<<"\n";
    }
    cout<<ans%MOD;
}
