#include<stdio.h>

int main(void){
  long int n,s,i,j;
  long int a[3001];
  long int x[3001][3001];
  
  scanf("%ld %ld\n",&n,&s);
  for(i=1;i<=n;i++){
    scanf("%ld ",&a[i]);
  }
  
  for(j=1;j<=s;j++){
    x[1][j]=0;
  }
  x[1][a[1]]=1;
  
  for(i=2;i<=n;i++){
    for(j=1;j<=s;j++){
      if(j<a[i]){
        x[i][j]=x[i-1][j];
      }else if(j==a[i]){
        x[i][j]=(x[i-1][j]+i)%998244353;
      }else{
        x[i][j]=(x[i-1][j]+x[i-1][j-a[i]])%998244353;
      }
    }
  }
  
  x[0][s]=0;
  long int m=0;
  for(i=0;i<=n-1;i++){
    m=(m+(x[i+1][s]-x[i][s])*(n-i))%998244353;
  }
  
  if(m<0){
    m=m+998244353;
  }
  printf("%ld",m);
  
  return 0;
}