#include<stdio.h>
int main(){
  int a,b,c,d,i,j=0,dt[1000],ls[1000],max,min,l,sum;
  while(1){
    scanf("%d",&a);
    if(a==0)break;
    sum=0;
    max=0;
    min=10000;
    for(i=0;i<a;i++){
      scanf("%d",&b);
      dt[i]=b;
    }
    for(i=0;i<a;i++){
      if(dt[i] > max) max=dt[i];
      if(dt[i] < min) min=dt[i]; 
    } 
    for(i=0;i<a;i++){
      if(dt[i]==max) 
	max=0;
      else if(dt[i]==min)
	min=0;
      else sum+=dt[i];
    }
    ls[j]=sum/(a-2);
    j++;
  }
  for(l=0;l<j;l++)
    printf("%d\n",ls[l]);
  return 0;
}