#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<int,int> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
set<string> c;
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
int main(){
  int n,k;
  cin>>n>>k;
  ll ans=0;
  for(int b=k+1;b<=n;b++){
      ans+=b-k;
       ans+=(b-k)*((n-n%b)/b-1);
       if(n%b>=k)ans+=(n%b-k+1);
     // cout<<ans<<endl;
  }
  if(k==0)ans-=n;
  cout<<ans<<endl;
}
