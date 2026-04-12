#include <bits/stdc++.h>

using namespace std;
int main()
{
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  int x=a*100+b*10+c;
  if(x%4==0)
      printf("YES");
  
  else
      printf("NO");
}