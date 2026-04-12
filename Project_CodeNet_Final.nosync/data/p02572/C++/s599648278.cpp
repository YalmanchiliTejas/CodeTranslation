#include <bits/stdc++.h>
using namespace std;
#define lmax LLONG_MAX
#define lmin LLONG_MIN
#define imax INT_MAX
#define imin INT_MIN
#define f(i,a,b) for(long long i=a;i<b;i++)
#define rf(i,a,b) for(long long i=a;i>=b;i--)
#define tc long long t;cin>>t;while(t--)
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define F first
#define S second
#define input(a,n) for(ll i=0;i<n;i++) cin>>a[i];
#define output(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" ";
#define up upper_bound
#define lo lower_bound
#define endl "\n"
#define mem(a) memset(a,-1,sizeof(a))
#define ll long long
#define umap unordered_map

ll modularExponentiation(ll x,ll n,ll M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll mod=1000000007;

    ll n;
    cin>>n;
    ll a[n];
    input(a,n);
    ll p=0;
    ll q=0;

    f(i,0,n){
        a[i]=a[i]%mod;
        p+=a[i];
        p%=mod;
        q+=(a[i]*a[i])%mod;
        q%=mod;
    }

    ll r = (p*p)%mod;
    ll x=modularExponentiation(2,mod-2,mod);
    cout<<((r-q+mod)%mod*x)%mod;

    return 0;
}