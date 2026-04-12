/**********************************

Sometimes the people whom no one ever imagines anything of,
do the things that no one can ever imagine.

***********************************/
#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-12)
#define ll long long int
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define pi 3.141592653589
#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?'\n':' ')
#define precise(n) cout << fixed << setprecision(n)
#define pcase cout<<"Case "<<++cs<<": "
const int mod=1e9+7;
ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}



int main()
{
      int a,b,n,i,j,k,cnt=1;


      cin >> n ;
      int arr[n];
      cin >> arr[0];
      k=arr[0];
      for(i=1;i<n;i++)
      {
          cin >> arr[i];

          if(arr[i]>=arr[0]&& arr[i]>=k) {cnt++;
          k=max(arr[i],arr[i-1]);
      }
      }
      cout << cnt << endl;



      return 0;
}
