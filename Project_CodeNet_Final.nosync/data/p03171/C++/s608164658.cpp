#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define         pb         push_back
#define         sf(x)      scanf("%d",&x)
#define         sfl(x)     scanf("%lld",&x)
#define         pf(x)      printf("%d\n",x)
#define         pfl(x)     printf("%lld\n",x)
#define         endl       '\n'
#define         pii        pair<int,int>
#define         mapii      map<int,int>
#define         mapll      map<ll,ll>
#define         mapci      map<char,int>
#define         mapcl      map<char,ll>
#define         mapsi      map<string,int>
#define         mapsl      map<string,ll>
#define         pll        pair<ll,ll>
#define         vi         vector<int>
#define         vl         vector<ll>
#define         vd         vector<double,double>
#define         all(c)     c.begin(),c.end()
#define         F          first
#define         S          second
#define         mp         make_pair
#define        ftc(x)      cerr << #x << ": " << x << " " << endl;
#define         PI         acos(-1)
#define         lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define        sqr(a)       ((a)*(a))


ll dp[3009][3009];
ll ar[3009];

ll sol(ll i,ll j)
{
    if(i == j)return ar[i];

    if(dp[i][j] != -1)return dp[i][j];

    ll ans = max(ar[i]-sol(i+1,j),ar[j]-sol(i,j-1));

    return dp[i][j] = ans;
}
int main()
{
    ll i,j,k,l,m,n;
    memset(dp,-1,sizeof dp);

    cin >> n;

    for(i=0;i<n;i++)cin >> ar[i];
    cout << sol(0,n-1) << endl;
}
