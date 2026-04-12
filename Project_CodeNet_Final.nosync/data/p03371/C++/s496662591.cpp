#include <bits/stdc++.h>
using namespace std;

int main(void){
  long long int a,b,c,x,y,ans,tmp_ans;
  long long int zero;
  zero=0;
  ans=1000000009;
  cin>>a>>b>>c>>x>>y;
  for(int i=0;i<2*max(x,y)+1;i+=2){
  	tmp_ans=c*i+a*max(x-i/2,zero)+b*max(y-i/2,zero);
  	ans=min(tmp_ans,ans);
  }
  cout<<ans<<endl;
}
