#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define FAST {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define f(i, a, b) for(ll i=a; i<b; i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pll pair<ll,ll>
#define LB lower_bound
#define UB upper_bound
#define endl "\n"
using namespace std;

int main()
{
    FAST
    ll M=1e9+7;
    ll n;cin>>n;
    ll a[n];
    f(i,0,n) cin>>a[i];
    ll suf[n];
    suf[n-1]=a[n-1];
    fr(i,n-2,0) suf[i]=(a[i]+suf[i+1])%M;
    ll ans=0;
    f(i,0,n-1)
    {
        ans = (ans + a[i]*suf[i+1])%M;
    }
    ans = (ans+M)%M;
    cout<<ans<<endl;
}
