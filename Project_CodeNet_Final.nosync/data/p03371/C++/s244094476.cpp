#include <bits/stdc++.h>
using namespace std;
#define rep(i,c,n) for(int i=c;i<n;i++)

int main(){
  int a,b,c,x,y;
  long long int ans,cntmin,cntmax;
  cin>>a>>b>>c>>x>>y;
  
  if(a+b>c*2){
    cntmin=min(x,y);
    cntmax=max(x,y);
    ans=c*2*cntmin;
    ans+=a*(x-cntmin)+b*(y-cntmin);
    ans=min(ans,c*2*cntmax);
  }
  else{ans+=a*x+b*y;}

  cout<<ans<<endl;
  
  return 0;
}
