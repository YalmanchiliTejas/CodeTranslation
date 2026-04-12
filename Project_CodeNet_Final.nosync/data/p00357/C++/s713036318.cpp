#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  vector<int> d(n);
  for(int &a:d) cin>>a;
  auto solve=[&](){
    int p=0;
    for(int i=0;i<n;i++){
      if(i>p) break;
      while((p+1)*10<=i*10+d[i]) p++;
    }
    return p>=n-1;
  };
  bool f=solve();
  reverse(d.begin(),d.end());
  f&=solve();
  cout<<(f?"yes":"no")<<endl;
  return 0;
}