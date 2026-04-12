# include<bits/stdc++.h>
using namespace std;

int main()
{
  int a = 0, b = 0;
  for(int i=0;i<3;i++)
  {
    char tmp;
    scanf(" %c", &tmp);
    if(tmp=='A') a++;
    else b++;
  }
  if(a==0||b==0) printf("No");
  else printf("Yes");
  return 0;
}