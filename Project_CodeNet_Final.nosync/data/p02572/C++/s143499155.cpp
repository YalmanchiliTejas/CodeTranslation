/*Author--Vishwas Agrawal*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vll vector<ll>
#define pb push_back
#define test ll t; cin>>t; while(t--)
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define M 1000000007LL
#define all(x) x.begin(),x.end()
#define sortall(x) sort(all(x))
#define inc(i,a,n) for (ll i=a;i<n;i++)
#define dec(i,a,n) for (ll i=n-1;i>=a;i--)
long long binpow(long long base, long long exp, int mod) {
   long long res = 1;
   while (exp > 0) {
      if (exp % 2 == 1)
         res= (res * base) % mod;
      exp = exp >> 1;
      base = (base * base) % mod;
   }
   return res;
}
long long mod(long long x){
return ((x%M+M)%M);
}

long long add(long long a, long long b){
return mod(mod(a)+mod(b));
}

long long mul(long long a, long long b){
return mod(mod(a)*mod(b));
}

int main()
{
  ll n;
  cin>>n;
  ll arr[n];
  ll sum=0;
   inc(i,0,n)
  {
     cin>>arr[i];
     sum=sum+arr[i];
  }
  ll ans=0;
  inc(i,0,n)
  {
     sum=sum-arr[i];
     ans=add(ans,mul(arr[i],sum));
  }
  cout<<ans<<endl;
  
  
   return 0;
}