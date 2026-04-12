#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
using vc=vector<char>;
using vvc=vector<vector<char>>;
const int inf=1000000007;
const int mod=1000000007;
const int max_n=100000;
void chmin(auto &a,auto b){if(b<a)a=b;}
void chmax(auto &a,auto b){if(a<b)a=b;}
ll modpower(ll a,ll b){  //aのb乗
  ll ans=1;
  while(b>0){
    a%=mod;
    if((b&1)==1){
      ans=ans*a%mod;
    }
    b>>=1;
    a*=a;
  }
  return ans;
}
ll modfacts(ll a){      //aの階乗
  ll ans=1;
  for(ll i=2;i<=a;i++)ans=ans*i%mod;
  return ans;
}
ll inv(ll a){           //aの逆元
  return modpower(a,mod-2);
}
ll modcom(ll a,ll b){   //aCb
  if(b>a)return 0;
  if(a<0||b<0)return 0;
  if(b*2>a)b=a-b;
  ll ans=inv(modfacts(b));
  rep(i,b)ans=ans*(a-i)%mod;
  return ans;
}
int main(){
  ll n,m,k;
  cin>>n>>m>>k;
  ll c=modcom(m+1,m-2),d=modcom(n+1,n-2);
  c*=modcom(m*n-2,k-2);
  c%=mod;
  c*=(n*n)%mod;
  c%=mod;
  d*=modcom(m*n-2,k-2);
  d%=mod;
  d*=(m*m)%mod;
  d%=mod;
  cout<<(c+d)%mod<<endl;
}
