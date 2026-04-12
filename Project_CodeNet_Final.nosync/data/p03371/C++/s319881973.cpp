#include <bits/stdc++.h>
using namespace std;

int main(void){
  long long int a,b,c,x,y,ans,tmp_ans;
  long long int zero;
  zero=0;
  ans=1000000009;
  cin>>a>>b>>c>>x>>y;
  if(min(a,b)>=2*c){
  	cout<<max(x,y)*2*c<<endl;
  	return 0;
  }
  if(a+b<=2*c){
  	cout<<a*x+b*y<<endl;
  	return 0;
  }
  for(int i=0;i<2*max(x,y)+1;i+=2){
  	tmp_ans=c*i+a*max(x-i/2,zero)+b*max(y-i/2,zero);
  	ans=min(tmp_ans,ans);
  }
  cout<<ans<<endl;
}
