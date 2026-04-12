#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
typedef pair<ll, ll> P;
const ll INF = 1LL << 60;
//const int MOD = 1000000007;
const ll MOD=998244353;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main(){
  ll n,x,m;
  cin>>n>>x>>m;
  vector<ll>a(101010),b;
  vector<ll> used(101010,0);
  ll sum=x;
  a[1]=x;
  used[x]=1;
  b.push_back(x);
  int start=0;
  bool hantei=false;
  for(int i=2;i<=n;i++){
    a[i]=((a[i-1]%m)*a[i-1])%m;
    //cout<<a[i]<<" ";
    sum+=a[i];
    if(used[a[i]]>0){
      start=a[i];
      hantei=true;
      break;
    }
    b.push_back(a[i]);
    used[a[i]]++;
  }
  if(hantei==false){
    cout<<sum<<endl;
    return 0;
  }
  ll wa1=0;
  int kazu=0;
  rep(i,b.size()){
    if(b[i]!=start)wa1+=b[i];
    else {
      kazu=i;
      break;
    }
  }
  ll wa2=0;
  for(int i=kazu;i<b.size();i++){
    wa2+=b[i];
  }
  ll ans=wa1+(n-kazu)/(b.size()-kazu)*wa2;
  int amari=(n-kazu)%(b.size()-kazu);
  if(amari!=0){
    for(int i=kazu;i<amari+kazu;i++){
      ans+=b[i];
    }
  }
  cout<<ans<<endl;
  return 0;
}

  