#include<bits/stdc++.h>
using namespace std;
using Int = long long;


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
