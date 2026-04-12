#include<bits/stdc++.h>

using namespace std;

typedef long long int 	ll;
typedef pair<int,int>   ii;
typedef vector< ii >   vii;
typedef vector<int>     vi;
typedef vector< vi >   vvi;

#define mm 100005
#define nn 1005
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(a) (int)(a.size())
#define all(a) a.begin(),a.end()
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define cases int t;  cin>>t;   while(t--)
#define check(a,n) forn(iiii,int(n)) cout<<ll(a[iiii])<<" "; cout<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int n;
ll a[55];

bool is(ll mid)
{
    ll b[55];
    forn(i,n) b[i]=a[i];
    while(mid>0)
    {
        int flag=0;
        sort(b,b+n);
        ll m=b[n-1]/n;
        b[n-1]%=n;
        forn(i,n-1)
        {
            b[i]+=m;
            if(b[i]>=n) flag=1;
        }
        mid-=m;
        if(flag==0&&mid>=0) return true;
    }
    return false;
}

int main()
{
    fast_io;
    cin>>n;
    int flag=1;
    forn(i,n)
    {
        cin>>a[i];
        if(a[i]>=n) flag=0;
    }
    if(flag) return cout<<0,0;
    ll l=0,r=1e18;
    while(l<r)
    {
        ll mid=(l+r)/2;
        if(is(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<r;
    return 0;
}
