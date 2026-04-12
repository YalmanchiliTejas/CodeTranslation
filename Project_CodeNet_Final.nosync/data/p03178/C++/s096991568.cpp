#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007
#define inf 1000000000000000007
#define eps 0.000001
#define pi 3.141592653589793
#define pii pair<int , int>
#define pdd pair<ld,ld>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vii vector<int>
#define vpl vector<pll>
#define vll vector<ll>
#define sti stack <int>
#define stll stack <ll>
#define mseti set <ll>
#define msetd multiset <ll, greater <ll> >
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound 
#define stp setprecision(20)//use fixed before stp
#define endl '\n'
int main()
{  
    FAST
    string s;
    ll n,d;
    cin>>s>>d;
    n=s.length();
    ll a[n+1][d][10];
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<d;j++)
        {
            for(ll k=0;k<10;k++)
            {
                a[i][j][k]=0;
                if(i==0&&j==0&&k==9)
                    a[i][j][k]=1;
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<d;j++)
        {
            for(ll k=0;k<10;k++)
            {
                ll q=j-k;
                q%=d;
                if(q<0)
                    q+=d;
                a[i][j][k]+=a[i-1][q][9];
                a[i][j][k]%=mod;
            }
        }
        for(ll j=0;j<d;j++)
        {
            for(ll k=1;k<10;k++)
            {
                a[i][j][k]+=a[i][j][k-1];
                a[i][j][k]%=mod;
            }
        }
    }
    ll m=0,ans=0,q;
    for(ll i=n;i>0;i--)
    {
        ll t=(int)(s[n-i])-48;
        q=-m;
        q%=d;
        if(q<0)
            q+=d;
        if(t!=0&&i!=1)
        {
            ans+=a[i][q][t-1];
        }
        if(i==1)
        {
            ans+=a[i][q][t];
        }
        ans%=mod;
        m+=t;
    }
    ans--;
    if(ans<0)
        ans+=mod;
    cout<<ans;
}