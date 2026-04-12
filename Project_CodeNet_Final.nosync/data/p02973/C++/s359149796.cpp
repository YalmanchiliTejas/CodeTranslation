#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> as(n);
  for(Int i=0;i<n;i++) cin>>as[i];

  multiset<Int> ss;
  ss.emplace(as[0]);
  for(Int i=1;i<n;i++){
    if(as[i]<=*ss.begin()){
      ss.emplace(as[i]);
    }else{
      auto it=ss.lower_bound(as[i]);
      assert(it!=ss.begin());
      --it;
      ss.erase(it);
      ss.emplace(as[i]);
    }
  }

  cout<<ss.size()<<endl;
  return 0;
}
