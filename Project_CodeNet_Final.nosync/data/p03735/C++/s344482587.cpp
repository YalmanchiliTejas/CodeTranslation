#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int N;
vector<ll> X,Y;

const ll INF=1e18;

int main(){
  cin>>N;
  X.resize(N);
  Y.resize(N);
  rep(i,N) cin>>X[i]>>Y[i];

  for(int i=0;i<N;i++){
      if(X[i]>Y[i]) swap(X[i],Y[i]);
  }

  int mat=0,mit=0;
  for(int i=0;i<N;i++){
      if(X[mit]>X[i]) mit=i;
      if(Y[mat]<Y[i]) mat=i;
  }

  ll ans=INF;
  if(mit!=mat){
      ll R=Y[mat]-X[mit];
      vector<pair<ll,ll>> v;
      for(int i=0;i<N;i++){
          if(i!=mit&&i!=mat) v.push_back(mkp(X[i],Y[i]));
      }
      sort(v.begin(),v.end());

      if(v.size()==0) ans=min(ans,R*abs(Y[mit]-X[mat]));
      else{
          ll ma=max(Y[mit],X[mat]);
          ll mi=min(Y[mit],X[mat]);// X...XY...Y

          ll ymi=v[0].second;
          ll yma=v[0].second;
          for(int i=1;i<v.size();i++){
              ll s=min(mi,min(ymi,v[i].first));
              ll t=max(ma,max(yma,v[i].first));
              s=min(s,v.back().first);
              t=max(t,v.back().first);

              ans=min(ans,R*(t-s));
              yma=max(yma,v[i].second);
              ymi=min(ymi,v[i].second);
          }

          ll ls=mi,lt=ma;//all X
          for(int i=0;i<v.size();i++){
              ls=min(ls,v[i].first);
              lt=max(lt,v[i].first);
          }
          ans=min(ans,R*(lt-ls));

          ls=mi;lt=ma;// all Y
          for(int i=0;i<v.size();i++){
              ls=min(ls,v[i].second);
              lt=max(lt,v[i].second);
          }
          ans=min(ans,R*(lt-ls));
      }
  }

  ll rmi=Y[mit],bma=X[mat];
  for(int i=0;i<N;i++){
      if(i==mat||i==mit) continue;
      rmi=min(rmi,Y[i]);
      bma=max(bma,X[i]);
  }
  ans=min(ans,(Y[mat]-rmi)*(bma-X[mit]));
  cout<<ans<<endl;

  return 0;
}
