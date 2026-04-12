#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  int n;
  cin>>n;
  vector<char> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  char ans=v[0];
  auto calc=[](char a,char b){return a=='T'?b:'T';};
  for(int i=1;i<n;i++) ans=calc(ans,v[i]);
  cout<<ans<<endl;
  return 0;
}

