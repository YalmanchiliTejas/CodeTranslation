#include <cstdio>

int main()
{
  int n;

  for(;;)
    {
      int j,min=1001,max=-1,sum=0;

      scanf("%d",&n);
      if(n==0) break;

      for(int i=0;i<n;i++){
	scanf("%d",&j);
	if(j<min) min=j;
	if(j>max) max=j;
	sum += j;
      }

      printf("%d\n",(sum-min-max)/(n-2));
    }
  
}