#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> p(n);
  for(Int i=0;i<n;i++) cin>>p[i];

  vector<Int> ans;
  auto mov=
    [&](Int k){
      if(k==0||k==n) return;
      ans.emplace_back(k);
      for(Int i=k;i<n;i++)
	swap(p[i],p[i-k]);
    };

  for(Int t=0;t<n;t++){
    mov(1);
    for(Int i=1;i<n;i++){
      if(p[0]<p[n-1]) mov(n-1);
      mov(1);
    }
  }
  
  assert(is_sorted(p.begin(),p.end()));
  cout<<ans.size()<<endl;
  for(Int x:ans) cout<<x<<endl;
  return 0;
}
