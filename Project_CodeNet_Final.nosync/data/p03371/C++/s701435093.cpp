#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  std::cin >> a>>b>>c>>x>>y;
  int val=0;
  if(2*c<a+b){
    val+=min(x,y)*c*2;
    int m=min(x,y);
    x-=m;
    y-=m;
    if(x!=0){
      val+=min(x*a,c*x*2);
    }
    if(y!=0){
      val+=min(y*b,c*y*2);
    }
  }else{
    if(x!=0){
      val+=min(x*a,c*x*2);
    }
    if(y!=0){
      val+=min(y*b,c*y*2);
    }
  }
  std::cout << val << std::endl;
}