#include <stdio.h>
int main()
{
  int n;
  while(scanf("%d", &n),n){
    int max=0,min=1000,s;
    long sum=0;
    for(int i=0; i<n; i++){
      scanf("%d",&s);
      sum+=s;
      max=max<s ? s : max;
      min=s<min ? s : min;
    }
    printf("%ld\n", (sum-min-max)/(n-2));
  }
}