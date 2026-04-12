#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n,t,e;
  cin>>n>>t>>e;
  vector<Int> x(n);
  for(Int i=0;i<n;i++) cin>>x[i];
  Int a=t-e,b=t+e;
  for(Int i=0;i<n;i++){
    Int tmp=0;
    while(tmp<a) tmp+=x[i];
    if(a<=tmp&&tmp<=b){
      cout<<i+1<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}

