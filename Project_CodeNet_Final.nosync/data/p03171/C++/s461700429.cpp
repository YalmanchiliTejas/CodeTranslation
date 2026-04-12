#include <bits/stdc++.h>
using namespace std;
#define scd(t) scanf("%d",&t)
#define scld(t) scanf("%ld",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define ffor(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define rfor(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define rep(i, j) ffor(i, 0, j, 1)
#define rrep(i, j) rfor(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
//#define f first
//#define s second
#define inf (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define trace1(x)                     cout <<#x<<": "<<x<< endl;
#define trace2(x, y)                 cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)              cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)           cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)        cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
const double pi=acos(-1.0);
typedef pair<long long int,long long int> pii;
typedef long long ll;
typedef vector<long long int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<long long int,long long int> mpii;
typedef set<long long int> sei;
typedef multiset<long long int> msei;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
ll dp[3000+1][3000+1];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll i,j,n,m;
    cin>>n;
    ll a[n+1];
    for(i=1;i<=n;i++)
    cin>>a[i];
    memset(dp,-1,sizeof(dp));
    if(n%2==0)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n-i+1;j++)
            {
                if(i==1)
                dp[i][j]=a[i];
                else if(i==2)
                dp[i][j]=max(a[j]-a[j+1],a[j+1]-a[j]);
                else
                {
                    dp[i][j]=max(a[j]-dp[i-1][j+1],a[i+j-1]-dp[i-1][j]);
                }
            }
        }
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n-i+1;j++)
            {
                if(i==1)
                dp[i][j]=a[i];
                else if(i==2)
                dp[i][j]=max(a[j]-a[j+1],a[j+1]-a[j]);
                else
                {
                    dp[i][j]=max(a[j]-dp[i-1][j+1],a[i+j-1]-dp[i-1][j]);
                }
            }
        }
    }
    cout<<dp[n][1];
    return 0;
}