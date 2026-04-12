#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,c,x,y,sum=0,minv,maxv;
  cin>>a>>b>>c>>x>>y;
  minv=min(x,y);
  maxv=max(x,y);
  if(a+b>c*2){
    if(minv*2*c+(x-minv)*a+(y-minv)*b<c*maxv*2){
      sum+=minv*2*c+(x-minv)*a+(y-minv)*b;
    }else{
      sum+=c*maxv*2;
    }
  }else{
    if(x*a+y*b<c*maxv*2){
      sum+=x*a+y*b;
    }else{
      sum+=maxv*2*c;
    }
  }
  cout<<sum<<'\n';
  
  return 0;
}
