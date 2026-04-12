#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
#define ss second
#define ff first 
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
const ll M=1000000007;
ll power(ll x,ll n){if(n==0)return 1;else if(n%2==0)return (power((x*x)%M,n/2))%M;else return ((x%M)*power(x,n-1)%M);}
ll ncr(int n,int r){if(r>n)return 0;if(r > n - r) r = n - r;ll ans = 1;
int i;for(i = 1; i <= r; i++){ans *= n - r + i;ans /= i;}return ans;}
ll nCrModpDP(ll n, ll r, ll p){ 
    ll C[r+1]; 
    memset(C, 0, sizeof(C)); 
    C[0] = 1;
    for (ll i = 1; i <= n; i++){ 
        for (ll j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 
ll ncrmod(ll n, ll r, ll p){ 
   if (r==0) 
      return 1; 
   ll ni = n%p, ri = r%p; 
   return (ncrmod(n/p, r/p, p) * 
           nCrModpDP(ni, ri, p)) % p;  
} 
ll modInverse(ll a,ll m) 
{ 
   ll m0 = m; 
   ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
       ll q = a / m; 
       ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 
const ll m=1000000009;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string str,ptr;
// cin>>str>>ptr;
// int l1=str.length();
// int l2=ptr.length();
// ll ans=0;
// for(int i=0; i<l2; i++){
// for(int j=0; j<l1; j++){

// }
// }
// cout<<ans;
ll n;
cin>>n;
ll num[n],sum[n],jum=0,ans=0;
for(int i=0; i<n; i++){
cin>>num[i];
jum+=num[i];
sum[i]=jum;
// cout<<sum[i]<<" ";
}
for(int i=0; i<n-1; i++){
// cout<<sum[n-i-1]<<" ";/
ans=((((num[i]%M)*((sum[n-1]-sum[i])%M))%M)+(ans%M))%M;
// cout<<ans<<" ";
}
cout<<ans;
return 0;
}