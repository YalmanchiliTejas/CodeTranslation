#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
#define rn(i,n) for(int i=1;i<=n;i++)

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int sum=0;
  if(a+b>2*c){
    sum+=min(x,y)*2*c;
    if(a>2*c){
      sum+=(x-min(x,y))*2*c;
    }else{
      sum+=(x-min(x,y))*a;
    }

    if(b>2*c){
      sum+=(y-min(x,y))*2*c;
    }else{
      sum+=(y-min(x,y))*b;
    }
  }else{

    if(a>2*c){
      sum+=(x)*2*c;
    }else{
      sum+=(x)*a;
    }

    if(b>2*c){
      sum+=(y)*2*c;
    }else{
      sum+=(y)*b;
    }
  }
  cout<<sum<<endl;
  return 0;
}
