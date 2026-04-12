#include <stdio.h>
 
int main()
{
    int n;
  scanf("%d",&n);
  int a[n],i;
  for(i=0;i<n;++i)
       scanf("%d",&a[i]);
  
  int j,cnt=1;
  int flag;
  for(i=1;i<n;++i)
  {
    flag=0;
    
    for(j=0;j<i;++j)
      {
          if(a[i]>=a[j])
            continue;
            
          else
            {
                flag=1;
                break;
            }
      }
    
    if(flag==0)
        cnt++;
  }
  
  printf("%d",cnt);
}