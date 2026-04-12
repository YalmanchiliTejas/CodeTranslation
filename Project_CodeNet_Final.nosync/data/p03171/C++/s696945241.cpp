#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define sll(x) scanf("%lld",&x)
#define prll(x) printf("%lld ",x)
#define pri(x) printf("%d ",x)
#define si(x) scanf("%d",&x)
#define el cout << "\n"
#define pb push_back
#define f first
#define s second
#define arrondi(a) (long long)floor(a+0.5);
#define NIL -1
ll N=500005;
ll MAX=9223372036854775807;
ll MOD=1000000007;
long double PI =4*atan(1);
ll n , m ,k;
ll nbr;

int main()
{
	IOS;


        ll n;
        cin >> n;
    vector<ll> L;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        L.push_back(x);
    }

    vector<vector<ll>> dp(n+1, vector<ll>(n+1,0));
    if(n%2==0)
    {
        for(int i=0;i<n;i++)
            dp[i][i]=-L[i];
        for(int len=2;len<=n;len++)
    {
        for(int i=0;i<=n-len;i++)
        {
            ll j=i+len-1;
            if(len%2==0)
                dp[i][j]=max(dp[i+1][j]+L[i],dp[i][j-1]+L[j]);
            else
                dp[i][j]=min(dp[i+1][j]-L[i],dp[i][j-1]-L[j]);

        }
    }
    }
    else
    {
       for(int i=0;i<n;i++)
            dp[i][i]=L[i];
        for(int len=2;len<=n;len++)
    {
        for(int i=0;i<=n-len;i++)
        {
            ll j=i+len-1;
            if(len%2==1)
                dp[i][j]=max(dp[i+1][j]+L[i],dp[i][j-1]+L[j]);
            else
                dp[i][j]=min(dp[i+1][j]-L[i],dp[i][j-1]-L[j]);

        }
    }
    }
    cout << dp[0][n-1];


    return 0;
}
