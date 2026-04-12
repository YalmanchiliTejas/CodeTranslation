#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  Int q;
  cin>>q;
  for(Int i=0;i<q;i++){
    Int k;
    cin>>k;
    cout<<lower_bound(a.begin(),a.end(),k)-a.begin()<<endl;
  }
  return 0;
}

