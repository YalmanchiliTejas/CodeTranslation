#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
  long long int ans,a,b,c,x,y;
  scanf("%lld %lld %lld %lld %lld\n",&a,&b,&c,&x,&y);
  if(a+b<c*2){
    printf("%lld\n",a*x+b*y);
  }
  else{
    if(x<y){
      ans=y*c*2;
      if(ans>x*c*2+(y-x)*b){
        ans=x*c*2+(y-x)*b;
      }
    printf("%lld\n",ans);
    }
    else{
      ans=x*c*2;
      if(ans>y*c*2+(x-y)*a){
        ans=y*c*2+(x-y)*a;
      }
    printf("%lld\n",ans);
    }
  }
  return 0;
}