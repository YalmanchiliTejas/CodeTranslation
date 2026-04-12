#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long
#define mod 1000000007
#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define f(i,n) for(ll i=0;i<n;i++)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define ms(v,n) memset((v),n,sizeof(v));
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define sll set<ll>
#define vll vector<ll>
#define vpll vector<pll>
#define maxi(a,b,c) max(a,max(b,c))
#define maxii(a,b,c,d) max(max(a,b),max(c,d))
#define mini(a,b,c) min(a,min(b,c))
#define md(a,b)  ((a%mod)*(b%mod)+mod)%mod 
#define ad(a,b)  (a%mod+b%mod+mod)%mod
#define nl endl
#define inf 1e18
#define cases ll t;cin>>t;while(t--)
#define BLOCK 500
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
 
using namespace std;


const int N=3005;
ll dp[N][N];
int main()
{
    
    fast
    ll n;
    cin>>n;
    ll a[n];

    f(i,n)
    cin>>a[i];

    

    for(ll l=n-1;l>=0;l--)
    {
        for(ll r=l;r<n;r++)
        {
            if(l==r)
            dp[l][r]=a[l];

            dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);

        }
    }

    cout<<dp[0][n-1];




    

       
    return 0;
    
}

