#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  
  long long sum=0,ans=1000000000;
  for(long long i=0;i<=max(y,x);i++){
      if(x-i<0) sum=2*c*i+b*(y-i);
      else if(y-i<0) sum=2*c*i+a*(x-i);
      else sum=2*c*i+a*(x-i)+b*(y-i);
      ans=min(sum,ans);
  }

  cout<<ans<<endl;
 
}