#include<cstdio>
using namespace std;
int x,y,z;
int main()
{
  scanf("%d%d%d",&x,&y,&z);x=(x-z)/(y+z);
  printf("%d",x);
  return 0;
}