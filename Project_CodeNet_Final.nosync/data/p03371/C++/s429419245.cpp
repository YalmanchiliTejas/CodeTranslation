#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
  int a,b,c,x,y;
  scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
  int sum=0;
  if(a+b<2*c){
    sum=a*x+b*y;
  }else{
    sum+=2*c*min(x,y);
    if(x>y){
      sum+=(x-y)*min(a,c*2);
    }else{
      sum+=(y-x)*min(b,c*2);
    }
  }
  printf("%d\n",sum);
  return 0;
}