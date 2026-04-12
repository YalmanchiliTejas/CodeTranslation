//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 2e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
ll a[MAXN];
ll dp[MAXN][3][2];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    if (n==2)
    {
        cout<<max(a[0],a[1]);
        return 0;
    }
    if (n==3)
    {
        cout<<max({a[0],a[1],a[2]});
        return 0;
    }
    for (int i=0;i<MAXN;i++)
    {
        for (int j=0;j<3;j++)
            for (int f=0;f<2;f++)
                dp[i][j][f]=-INFLL;
    }
    if (n%2==0)
    {
        dp[2][1][1]=a[1];
        dp[2][0][0]=a[0];
        for (int i=3;i<=n;i++)
        {
            dp[i][0][1]=max(dp[i][0][1],dp[i-1][0][0]+a[i-1]);
            dp[i][1][1]=max(dp[i][1][1],dp[i-1][1][0]+a[i-1]);
            if (i!=n)
            dp[i][0][0]=max(dp[i][0][0],dp[i-1][0][1]);
            else
                dp[i][0][0]=dp[i][0][0];
            if (i!=n)
            dp[i][1][0]=max(dp[i][1][0],max(dp[i-1][0][0],dp[i-1][1][1]));
            else
                dp[i][1][0]=max(dp[i][1][0],dp[i-1][0][1]);
        }
        cout<<max(dp[n][1][0],dp[n][1][1]);
    }
    else
    {
        dp[2][1][1]=a[1];
        dp[2][0][0]=a[0];
        dp[2][2][0]=0;
        for (int i=3;i<=n;i++)
        {
            dp[i][0][1]=max(dp[i][0][1],dp[i-1][0][0]+a[i-1]);
            dp[i][1][1]=max(dp[i][1][1],dp[i-1][1][0]+a[i-1]);
            if (i!=n)
                dp[i][0][0]=max(dp[i][0][0],dp[i-1][0][1]);
            else
                dp[i][0][0]=dp[i][0][0];
            if (i!=n)
                dp[i][1][0]=max(dp[i][1][0],max(dp[i-1][0][0],dp[i-1][1][1]));
            else
                dp[i][1][0]=max(dp[i][1][0],dp[i-1][0][1]);
            ///////////////////////////////
            dp[i][2][1]=max(dp[i][2][1],dp[i-1][2][0]+a[i-1]);
            if (i!=n)
            dp[i][2][0]=max({dp[i][2][0],dp[i-1][2][1],dp[i-1][1][0]});
            else
            {
                dp[i][2][0]=max({dp[i][2][0],dp[i-1][1][1],dp[i-2][0][1]});
            }
        }
//        for (int i=0;i<=n;i++)
//        {
//            for (int k=0;k<3;k++)
//            {
//                cout<<i<<" "<<k<<" "<<dp[i][k][0]<<" "<<dp[i][k][1]<<'\n';
//            }
//        }
        cout<<max(dp[n][2][0],dp[n][2][1]);
    }



}
