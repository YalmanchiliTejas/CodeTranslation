#include<bits/stdc++.h>
using namespace std;
#define rei(i,a,n) for(int i=(a);i<(n);i++)
#define red(i,a,n) for(int i=(a)-1;i>=(n);i--)
#define rep(i,n) rei(i,0,n)
#define rem(i,n) red(i,n,0)
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
int msb(ll x)
{
    union{double a;int32_t b[2];};
    a=x;
    return (b[1]>>20)-1023;
}
int mx=(int)1e9+7;
void sol()
{
    int n;
    ll s=0,ans=0;
    cin>>n;
    vi a(n);
    rep(i,n)
    {
        cin>>a[i];
        ans+=s*a[i];
        ans%=mx;
        s+=a[i];
        s%=mx;
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)sol();
}
