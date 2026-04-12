  #include<bits/stdc++.h>
  using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define ll  long long
  #define ld long double
  #define pb push_back
  #define mp3 make_pair
  #define rep1(i,a,b) for(ll i=a;i<=b;i++)
  #define rep2(i,a,b) for(ll i=a;i<b;i++)
  const ll  mod=1e9+7;
  template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
  template<typename T> T add(T a,T b,ll m){a+=b;while(a>=0)a-=m;while(a<0)a+=m; return a;}
  template<typename T> T mul(T a,T b,ll m){return (a*1ll*b)%m;}

 int main(){
   IOS;
  ll n;
  cin>>n;
  ll a[n+1];
  for(ll i=1;i<=n;i++){
    cin>>a[i];
  }
  ll pre[n+1]={0};
  for(ll i=1;i<=n;i++){
    pre[i]=add(a[i],pre[i-1],mod);
  }
  ll ans=0;
  for(ll i=1;i<=n;i++){
    ans=add(ans,mul(a[i],(pre[n]-pre[i]),mod),mod);
  }
  cout<<ans<<endl;
 }