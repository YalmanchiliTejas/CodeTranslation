#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 1ll<<59


int main(){
  ll i,j;
  ll n,s,t;
  cin>>n>>s>>t;

  ll d[n+1][n+1];
  for(i=1;i<=n;i++){
      cout<<"? "<<s<<" "<<i<<endl;
      cout.flush();
      ll x;
      cin>>x;
      d[s][i]=x;
  }
  for(i=1;i<=n;i++){
      cout<<"? "<<i<<" "<<t<<endl;
      cout.flush();
      ll x;
      cin>>x;
      d[i][t]=x;
  }

  vector<P> v;
  for(i=1;i<=n;i++){
      if(i!=s&&i!=t&&d[s][i]+d[i][t]==d[s][t]){
          v.pb(P(d[s][i],i));
      }
  }
  v.pb(P(d[s][t],t));
  sort(v.begin(),v.end());


  ll tem=0;

  vector<ll> ans;
  ans.pb(s);

  while(tem!=v.size()-1){
      ans.pb(v[tem].se);
      ll prev=v[tem].se;
      ll syu=0;
      for(i=tem+1;i<v.size();i++){
          cout<<"? "<<prev<<" "<<v[i].se<<endl;
          cout.flush();
          ll x;
          cin>>d[prev][v[i].se];
          if(d[s][prev]+d[prev][v[i].se]==d[s][v[i].se]){
              syu=1;
              tem=i;
              ans.pb(v[i].se);
          }
          if(syu==1) break;
      }
  }
  cout<<"!";
  for(i=0;i<ans.size();i++) cout<<" "<<ans[i];
  cout<<endl;
  cout.flush();

  return 0;
}
