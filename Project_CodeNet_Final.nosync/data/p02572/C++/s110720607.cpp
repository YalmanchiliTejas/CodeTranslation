///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define                          ll                          long long int
ll gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

#define                          in(x)                       scanf("%lld",&x)
#define                          in2(x,y)                    scanf("%lld %lld",&x,&y)
#define                          in3(x,y,z)                  scanf("%lld %lld %lld",&x,&y,&z)
#define                          out(x)                      printf("%lld\n",x)
#define                          cy                          printf("YES\n")
#define                          cn                          printf("NO\n")
#define                          inf                         1e18
#define                          neg                         -1e18
#define                          mx                          2111111
#define                          fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define                          fi                          frist
#define                          si                          second
#define                          ce                          cout<<endl
#define                          pb                          push_back
#define                          vc(x)                       x.begin(),x.end()
#define                          pb                          push_back
#define                          pi                          pair<ll,ll>
#define                          debug                       printf("ok\n");
#define                          pg                          pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> >

ll mod=1e9+7;
inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
ll findProductSum(ll A[], ll n)
{

    ll array_sum = 0;
    for (ll i = 0; i < n; i++)
    {
        array_sum = modAdd(array_sum,A[i]);
    }

 ll mul =0;
    ll array_sum_square = modMul(array_sum,array_sum);

    ll individual_square_sum = 0;
    for (ll i = 0; i < n; i++)
    {
        individual_square_sum += (A[i]*A[i])%mod;
        individual_square_sum%=mod;
    }
    ll summm=0;
    ll x=modSub(array_sum_square,individual_square_sum);
    ll z=modDiv(x,2);
    return z;
}
int main(){


    ll n,i,j,s=0,ans=0;

   cin>>n;
   ll a[n+9];
    for(i=0;i<n;i++){
        in(a[i]);
    }
   cout<<findProductSum(a,n)<<endl;

}
