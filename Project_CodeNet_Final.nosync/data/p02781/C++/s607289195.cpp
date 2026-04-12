#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define inf 1000000000000000
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define rep(n) for(ll i = 0; i < n; i++)
#define repi(i,n) for(ll i = 0; i < n; i++)
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
 
using namespace std;

ll powa(ll a, ll b, ll c)
{
    a%=c;
    ll res = 1;
    while(b>0)
    {
        if(b&1)
            res*=a, res%=c;
        a*=a, a%=c;
        b>>=1;
    }
    return res;
}

#define N 100005

ll fact[N];
ll ifact[N];
ll ncr(ll n, ll r)
{
    if(r>n)
        return 0;
    ll ans = fact[n];
    ans*=ifact[r];
    ans%=mod;
    ans*=ifact[n-r];
    ans%=mod;
    return ans;
}

ll get(string s, ll k)
{
    if(k == 0)
        return 1;
    if(s.length() == 0)
        return 0;
    ll len = s.length();
    if(len<k)
        return 0;
    ll p1 = 0;
    ll mul = 1;
    rep(k)
        mul*=9;
    for(ll i=1;i<=len-1;i++)
        p1+=mul*(ncr(i-1,k-1));
    
    mul = 1;
    rep(k-1)
        mul*=9;
    
    for(ll dig=1;dig<((ll)s[0]-'0');dig++)
        p1+=mul*ncr(len-1,k-1);
    //cout<<"for "<<s<<" = "<<p1<<"\n";
    reverse(s.begin(), s.end());
    s.pop_back();
   while(s.length()>0 && s.back() == '0')
        s.pop_back();
    if(s.length()>0)    
            reverse(s.begin(), s.end());
    return p1 + get(s,k-1);
}


int main()
{
   FAST/**/
   
   fact[0] = 1;
   for(ll i=1;i<N;i++)
        fact[i] = fact[i-1]*i, fact[i]%=mod;
   for(ll i=0;i<N;i++)
        ifact[i] = powa(fact[i],mod-2,mod);
   
   string n;
   cin>>n;
   
   ll k;
   cin>>k;
   
   ll ans = get(n,k);
   ll cnt =  0;
   if(cnt == k)
        ans++;
   cout<<ans;
   
   return 0;        
}  