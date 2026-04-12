#include<cstdio>
int main()
{
  int x;
  while(scanf("%d",&x)!=EOF)
  {
    if(x==3||x==5||x==7)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}