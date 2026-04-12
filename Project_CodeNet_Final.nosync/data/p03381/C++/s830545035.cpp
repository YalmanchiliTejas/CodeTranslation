#include<bits/stdc++.h>
using namespace std;
using ll = long;
main(){
  int n;cin>>n;
  vector<ll> a(n);
  for(auto&q:a)cin>>q;
  auto b=a;
  sort(b.begin(),b.end());
  for(int i=0;i<n;++i){
    ll key=a[i],mid=(n-2)/2;
    ll idx=lower_bound(b.begin(),b.end(),key)-b.begin();
    if(idx<=mid) mid++;
    cout<<b[mid]<<endl;
  }
}
