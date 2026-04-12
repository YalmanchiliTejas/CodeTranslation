
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 1000000007
#define PI 3.14159265359
#define dij priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
typedef long long ll;
//
int main(){
  ll n,x,m;cin>>n>>x>>m;
  vector<ll> v(100001);
  v[0]=x;
  FOR(i,1,100000){
    v[i]=(v[i-1]*v[i-1])%m;
  }
  map<ll,ll> mp;
  ll co=0;
  rep(i,1000001){
    mp[v[i]]++;
    co++;
    if(mp[v[i]]==2)break;
  }
  co--;
  //rep(i,10)cout<<v[i]<<" ";
  //cout<<endl;
  //cout<<co;
  ll co2=0;
  rep(i,v.size()){
    if(v[i]==v[co]){
      co2=i;
      break;
    }
  }
  //cout<<co<<" "<<co2<<endl;;
  ll dif=co-co2;
  ll dd=0;
  FOR(i,co2,co-1){
    dd+=v[i];
  }
  ll da=0;
  FOR(i,0,co2-1){
    da+=v[i];
  }
  //cout<<dd<<" "<<da;
  ll ans=0;
  if(n<co2){
    rep(i,n)ans+=v[i];
  }else{
    rep(i,co2)ans+=v[i];
    n=n-co2;
    ans+=(n/dif)*dd;
    FOR(i,co2,co2+n%dif-1)ans+=v[i];
  }
  //cout<<dif<<endl;
  cout<<ans<<endl;
}