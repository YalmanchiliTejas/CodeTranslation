#include<bits/stdc++.h>
using namespace std;
main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int piz=min(x,y),mon=0;
  if(a+b>c*2){
    mon=c*piz*2;
  }else{
    mon=(a+b)*piz;
  }
  if(piz==x){
    piz=y-x;
    if(b>c*2)  mon+=c*2*piz;
    else mon+=b*piz;
  }else{
    piz=x-y;
    if(a>c*2) mon+=c*2*piz;
    else mon+=a*piz;
  }
  cout<<mon<<endl;
  return 0;
}
