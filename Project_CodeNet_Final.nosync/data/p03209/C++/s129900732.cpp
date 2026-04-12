#include<bits/stdc++.h>
using namespace std;
#define int long
main(){
  int n,x,res=0;
  cin>>n>>x;
  auto w = [](int k){return (1l<<(k+2l))-3l;};
  auto p = [](int k){return (1l<<(k+1l))-1l;};
  while(x>0){
    if(!n){res+=!!x;break;}
    if(w(n)==x){res+=p(n);break;}
    if(w(n-1)+2<=x){res+=p(n-1)+1;x-=w(n-1)+2;n--;}
    else if(1<x){x--;n--;}
    else break;
  }
  cout<<res;
}