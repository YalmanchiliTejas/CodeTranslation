#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
  vector<P> vec;
  vector<ll> comp;
  ll n;
  cin>>n;
  for(int i=0;i<n;i++){
    ll a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    vec.push_back(P(a,b));
    comp.push_back(a);
    comp.push_back(b);
  }
  sort(comp.begin(),comp.end());
  comp.erase(unique(comp.begin(),comp.end()),comp.end());
  sort(vec.begin(),vec.end());
  ll max_max=0,midx=0;
  for(int i=0;i<n;i++){
    if(vec[i].second>=max_max){
      max_max=vec[i].second;
      midx=i;
    }
  }
  ll min_max=0,max_min=174417441744,min_min=vec[0].first;
  for(int i=0;i<n;i++){
    min_max=max(min_max,vec[i].first);
    max_min=min(max_min,vec[i].second);
  }
  ll ans=(min_max-min_min)*(max_max-max_min);
  ll k=(max_max-min_min);
  if(midx!=0){
    ll ridx=1;
    multiset<ll> ms;
    for(int i=1;i<n;i++) ms.insert(vec[i].first);
    ms.insert(vec[0].second);
    for(int i=1;i<n;i++){
      ans=min(ans,k*((*ms.rbegin())-(*ms.begin())));
      ms.erase(ms.find(vec[i].first));
      ms.insert(vec[i].second);
      ans=min(ans,k*((*ms.rbegin())-(*ms.begin())));
    }
  }
  cout<<ans<<endl;
}
