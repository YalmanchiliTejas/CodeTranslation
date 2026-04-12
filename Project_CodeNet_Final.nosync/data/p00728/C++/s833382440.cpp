#include <cstdio>

int main(){
  int n;
  for(;;){
    int sum=0,min=1000,max=0;
    scanf("%d",&n);
    if(n==0) break;
    for(int i=0; i<n; i++){
      int m;
      scanf("%d",&m);
      if(m<min) min=m;
      if(m>max) max=m;
      sum+=m;
    }
    printf("%d\n",(sum-min-max)/(n-2));
  }
}