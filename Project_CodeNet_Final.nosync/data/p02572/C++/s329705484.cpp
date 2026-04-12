#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=0x61=97 '0'=0x30=48
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef string str;
typedef pair<int,int> pairii;
typedef vector<ll> veci;
const double pi=3.1415926535;
const ll  mod=2000000014;
//桁数指定　cout << fixed << setprecision(2)
int main() {
  int n;ll s=0;ll ans=0;
  cin>>n;
  veci v(n);
  rep(i,n){cin>>v[i];v[i]%=mod;s+=v[i]; s%=mod;}s%=mod;
  ans=(s*s)%mod;
  rep(j,n){ans+=mod*mod-(ll)v[j]*v[j];ans%=mod;}ans%=mod;
  cout<<(ans/2)%(mod/2)<<endl;
}
