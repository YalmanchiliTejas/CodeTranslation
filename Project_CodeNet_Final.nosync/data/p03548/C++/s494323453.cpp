#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int X,Y,Z;
  cin>>X>>Y>>Z;
  X-=Z;
  int ans=X/(Y+Z);
  cout<<ans<<endl;
  return 0;
}