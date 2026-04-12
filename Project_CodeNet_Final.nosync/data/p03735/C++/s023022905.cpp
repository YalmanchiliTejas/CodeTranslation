#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod;
#define mul(a,b) a=a*b%mod;
#define N 200010
ll n,x[N],y[N];
int main(){
  cin>>n;
  ll mi=1e17,pmi=-1,ma=-1e17,pma=-1;
  ll xma=-1e17,ymi=1e17;
  for(int i=0;i<n;i++){
      cin>>x[i]>>y[i];
      if(x[i]>y[i])swap(x[i],y[i]);
      if(x[i]<mi)mi=x[i],pmi=i;
      if(y[i]>ma)ma=y[i],pma=i;
      chmax(xma,x[i]);
      chmin(ymi,y[i]);
  }
  ll ans=(xma-mi)*(ma-ymi);
  if(pmi!=pma){
      ll k1=y[pmi],k2=x[pma];
      vector<pair<ll,ll> >v;
      multiset<ll> s;
      s.insert(k1); s.insert(k2);
      for(int i=0;i<n;i++){
          if(i==pmi||i==pma)continue;
          v.push_back(make_pair(x[i],y[i]));
          s.insert(x[i]);
      }
      sort(v.begin(),v.end());
      for(int i=0;i<v.size();i++){
          s.erase(s.find(v[i].first));
          s.insert(v[i].second);
          ll vl=*s.begin();
          auto it=s.end(); it--;
          ll vr=*it;
          chmin(ans,(ma-mi)*(vr-vl));
      }
  }
  cout<<ans<<endl;
  return 0;
}
