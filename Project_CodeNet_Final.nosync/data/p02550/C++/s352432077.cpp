//------ © daxkofficial™ ------//
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
 
#define ll long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define srt(x) sort((x).begin(), (x).end());
#define clr(x) memset(x, 0, sizeof(x));
#define mem(a,val) memset(a,val,sizeof(a));
#define trace(x) for(auto it:x) cout<<it<<' '; cout<<"\n";
#define sumv(x, w) for(auto it:x) w+=it;
#define traca(A, n) for(ll i=0; i<n; i++) cout<<A[i]<<' '; cout<<"\n";
#define pll pair<ll,ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vb vector<bool>
#define vc vector<char>
#define vpll vector<pll>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define cy cout<<"YES"<<"\n";
#define cn cout<<"NO"<<"\n";
#define nl cout<<"\n";
#define chk cout<<"*\n";
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
/*-----------------------------Modular Arithmetic---------------------*/
inline ll add(ll x,ll y,ll mod){x+=y; if(x>=mod) return x-mod; return x;}
inline ll sub(ll x,ll y,ll mod){x-=y; if(x<0) return x+mod; return x;}
inline ll mul(ll x,ll y,ll mod){return (x*1ll*y)%mod;}
inline ll power(ll x,ll y,ll mod){ll ans=1; while(y){if(y&1) ans=mul(ans,x,mod); x=mul(x,x,mod); y>>=1;} return ans;}
inline ll inv(ll x,ll mod){return power(x,mod-2,mod);}
 
 
 
/*------------------------ Important Functions ----------------------------*/
 
ll gcd(ll a , ll b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
 
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
 
ll min(ll x, ll y, ll z) 
{ 
    return min(min(x, y), z); 
} 
 
 
/*------------------------ Few More Functions ----------------------------*/
 
 
 
 
ll factmod(ll n, ll p) {
    ll res = 1;
    while (n > 1) {
        res = (res * ((n/p) % 2 ?  p-1 : 1)) % p;
        for (ll i = 2; i <= n%p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}
 
ll largestPower(ll n, ll p) 
{ 
    ll x = 0; 
      while (n) { 
        n /= p; 
        x += n; 
    } 
    return x; 
} 
  
ll modFact(ll n, ll p) 
{ 
    if (n >= p) 
        return 0; 
    ll res = 1; 
    bool isPrime[n + 1]; 
    memset(isPrime, 1, sizeof(isPrime)); 
    for (ll i = 2; i * i <= n; i++) { 
        if (isPrime[i]) { 
            for (ll j = 2 * i; j <= n; j += i) 
                isPrime[j] = 0; 
        } 
    } 
      for (ll i = 2; i <= n; i++) { 
        if (isPrime[i]) { 
            ll k = largestPower(n, i); 
              res = (res * power(i, k, p)) % p; 
        } 
    } 
    return res; 
}
 
 
 
/*------------------------ Trouble begins here ----------------------------*/
 
 
const ll M=1e9+7, M2=998244353;
const ll N=1e5+100;




void solve()
{
    ll n, x, mod, i, j;
    cin>>n>>x>>mod;
    vll A(100000);
    map<ll, ll> M;
    A[0]=x;
    ll note=n;
    ll sum=0;
    M[x]=0;
    ll f=0;
    for(i=1; i<n; i++)
    {
        A[i]=mul(A[i-1], A[i-1], mod);
        if(M[A[i]]==0)
        M[A[i]]=i;
        else
        {
            ll s = M[A[i]];
            //cout<<s<<"\n";
            for(j=0; j<s; j++)
            {sum+=A[j];
            //sum%=mod;
            }
            ll y = 0;
            for(j=s; j<i; j++)
            y+=A[j];
            sum+=y*((n-s)/(i-s));
            ll r = (n-s)%(i-s);
            for(j=s; j<s+r; j++)
            {sum+=A[j];
            //sum%=mod;
            }
            f=1;
            break;
        }
        
    }
    if(f==0)
    {
        for(i=0; i<n; i++)
        {
            sum+=A[i];
            
        }
    }
    cout<<sum;
    return;
}





int main()
{

    fastio
    
    ll tc=1, ttt=0;
    //cin>>tc;
    while(tc--)
    {
        //ttt++;
        //cout<<"Test case : "<<ttt<<"\n";
        //chk
        solve();
    }
 
    return 0;
}
/*          
            
            ❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️          
 
 
                                        
 
                                ♥  ♥       ♥  ♥
                               ♥     ♥   ♥     ♥
                               ♥       ♥       ♥
                                ♥             ♥
                                 ♥           ♥
                                   ♥       ♥
                                     ♥   ♥
                                       ♥
 
 
 
*/
