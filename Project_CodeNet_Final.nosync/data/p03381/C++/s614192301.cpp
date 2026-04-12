#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> x(n);
  for(Int i=0;i<n;i++) cin>>x[i];
  auto y=x;
  sort(y.begin(),y.end());
  for(Int i=0;i<n;i++){
    Int k=lower_bound(y.begin(),y.end(),x[i])-y.begin();
    if(k<n/2){
      cout<<y[n/2]<<endl;
    }else{
      cout<<y[n/2-1]<<endl;
    }
  }
  
  return 0;
}
