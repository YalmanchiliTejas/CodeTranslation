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
  Int h,w;
  cin>>h>>w;
  vector<string> st(h);
  for(Int i=0;i<h;i++) cin>>st[i];

  vector<Int> us,vs;
  for(Int i=0;i<h;i++){
    for(Int j=0;j<w;j++){
      if(st[i][j]!='B') continue;
      us.emplace_back(i+j);
      vs.emplace_back(i-j);
    }
  }
  sort(us.begin(),us.end());
  sort(vs.begin(),vs.end());

  cout<<max(us.back()-us.front(),vs.back()-vs.front())<<endl;
  return 0;
}

