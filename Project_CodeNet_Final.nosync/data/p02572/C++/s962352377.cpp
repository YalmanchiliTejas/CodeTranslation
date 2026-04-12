#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define deb(a,b,c) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl;
 
typedef long long int ll;
typedef string str;
 
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;     
  
    x = x % p;   
    while (y) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;  
        x = (x*x) % p; 
    } 
    return res; 
} 
 
ll nCrModP(ll n, ll r, ll p) 
{ 
    if (!r) 
      return 1; 
  
	ll fac[n+1]; 
   	fac[0] = 1; 
    for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* power(fac[r], p-2,p) % p * power(fac[n-r], p-2,p) % p) % p; 
}
 
ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);
}
 
void fast(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main ()
{
	
	ll t,n,m,k,i,j,a,b=pow(10,9)+7;
	// cin >> t;
    str st,s;
    cin >> n;
    ll arr[n+2];
    ll sum[n+2]={0};
    for(i=1;i<=n;i++)
    {
        cin >> arr[i];
        sum[i]=arr[i]+sum[i-1];
        sum[i]%=b;
    }
    ll ans=0;
    for(i=2;i<=n;i++)
    {
        a=(arr[i]%b)*(sum[i-1]%b);
        a%=b;
        ans+=a;
        ans%=b;
    }
    cout << ans << "\n";
    return 0;
}