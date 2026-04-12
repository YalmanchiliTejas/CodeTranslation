#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define per(i,s,n) for(int i=n-1;i>=s;i--)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<ll, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;


ll mod;




struct mint {
  ll x; 
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};


int main(){
  ll n;
  cin>>n;
  ll m;
  cin>>m;
  
  ll l,h;
  
  cin>>mod;
  
  mint a[mod+10];
  int ch[mod+10];
  rep(i,mod){
    ch[i]=-1;
  }
  
  a[0]=m;
  
  ll cnt=0;
  ch[m]=0;
  
  Rep(i,1,mod+10){
    a[i]=a[i-1]*a[i-1];
    if(ch[a[i].x]==-1) ch[a[i].x]=i;
    else{
      l=ch[a[i].x];
      h=i;
      break;
    }
  }
  
  Rep(i,l,h){
    cnt+=a[i].x;
  }
  
  ll ans=0;
  rep(i,l){
    if(n==0) break;
    ans+=a[i].x;
    n--;
  }
  
  ll c=n/(h-l);
  
  
  ans+=c*cnt;
  
  rep(i,n-c*(h-l)){
    ans=ans+a[i+l].x;
  }
  
  cout<<ans<<endl;
  
  
  
  
    
  
  
}