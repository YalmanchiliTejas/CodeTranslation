#include <stdio.h>
int main()
{
  int n,ans,i,j,x;
  scanf("%d",&n);
  int h[n];
  ans=0;
  for(i=0;i<n;i++)scanf("%d",&h[i]);
  for(i=n-1;i>=0;i--){
    x=0;
    for(j=i-1;j>=0;j--){
      x+=(h[i]>=h[j])?1:0;
     // printf("%d-%d ",h[i],h[j]);
    }
   // printf("%d=%d\n",i,x);
    if(i==x) ans++;
  }
 printf("%d",ans);
}