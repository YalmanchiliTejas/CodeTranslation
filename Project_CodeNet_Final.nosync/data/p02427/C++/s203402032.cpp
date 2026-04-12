#include<bits/stdc++.h>
using namespace std;

signed main(){

  int n;
  cin>>n;

  vector<vector<unsigned long>> a(1<<n);

  for(int b=0;b<(1<<n);++b){
    bitset<20> bit(b);
    a[b].resize(bit.count()+1);
    a[b][0] = bit.to_ulong();
    int idx = 1;
    for(int i=0;i<n;++i){
      if(bit[i])a[b][idx++]=i;
    }
  }
  sort(a.begin(),a.end(),[](auto& a,auto& b){return a[0]<b[0];});

  for(auto v:a){
    cout<<v[0]<<":";
    for(int i=1;i<v.size();++i){
      cout<<" "<<v[i];
    }
    cout<<endl;
  }

}
