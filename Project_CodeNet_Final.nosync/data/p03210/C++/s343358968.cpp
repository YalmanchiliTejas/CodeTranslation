#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int x;
  cin>>x;
  if(x==3||x==5||x==7) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
