#include<bits/stdc++.h>
using namespace std;
char a,b;
int main()
{
  a=getchar();
  while (a!=EOF)
  {
    b=getchar();
    if (a=='A'&&b=='C')
    {
      printf("Yes\n");
      return 0;
    }
    a=b;
  }
  printf("No\n");
  return 0;
}
