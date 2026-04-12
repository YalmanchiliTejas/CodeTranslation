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
  int n;
  cin>>n;
  for(int b=0;b<(1<<n);b++){
    cout<<b<<":";
    for(int i=0;i<n;i++)
      if((b>>i)&1) cout<<" "<<i;
    cout<<"\n";
  }
  cout<<flush;
  return 0;
}

