#include<stdio.h>
int main(){
  int n,m,f=0,a,b;
  scanf("%d %d",&n,&m);
  while(m--){
    scanf("%d %d",&a,&b);
    if(a==0)printf("%d\n",(f+b-1)%n+1);
    else    f=(f+b)%n;
  }
  return 0;
}
      

