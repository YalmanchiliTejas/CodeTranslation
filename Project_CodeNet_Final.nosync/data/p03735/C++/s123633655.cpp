#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

const ll INF=1e18;

int main(){
  int N; cin>>N;
  pair<ll,ll> X[N];
  ll mi=INF,ma=-INF;
  rep(i,N){
    ll x,y; cin>>x>>y;
    if(x>y) swap(x,y);
    mi=min(mi,x);
    ma=max(ma,y);
    X[i]={x,y};
  }
  ll Rmi=mi,Rma=-INF,Bmi=INF,Bma=ma;
  rep(i,N){
    ll x=X[i].first, y=X[i].second;
    Rma=max(Rma,x);
    Bmi=min(Bmi,y);
  }
  ll ans=(Rma-Rmi)*(Bma-Bmi);
  Rmi=mi,Rma=ma,Bma=-INF,Bmi=INF;
  sort(X,X+N);
  ll Ymi=INF;
  Bma=X[N-1].first;
  for(int i=1;i<N;i++){
    Ymi=min(Ymi,X[i-1].second);
    Bma=max(Bma,X[i-1].second),Bmi=min(X[i].first,Ymi);
    ans=min(ans,(Rma-Rmi)*(Bma-Bmi));
  }
  cout<<ans<<endl;
  return 0;
}
