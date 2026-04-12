#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
  int n;
  cin>>n;
  vector<ll> v(n);
  vector< P > t(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
    t[i]=P(v[i],i);
  }

  sort(t.begin(),t.end());

  vector<ll> ans(n);
  for(int i=0;i<n;i++){
    ll fi=t[i].first;
    ll se=t[i].second;
    if(i<n/2){
      ans[se]=t[n/2].first;
    }else{
      ans[se]=t[n/2-1].first;
    }
  }

  for(int i=0;i<n;i++){
    cout<<ans[i]<<endl;
  }
  return 0;
}
