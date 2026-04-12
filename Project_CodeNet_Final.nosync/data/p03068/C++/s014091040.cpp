#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
  int n,k;
  char s[16],ch;
  scanf("%d",&n);
  scanf("%s",s);
  scanf("%d",&k);
  
  ch = s[k-1];
  k = strlen(s);
  
  for (auto i = 0 ; i < k ; ++i)
    putchar(s[i] == ch ? s[i] : '*');
  return 0;
}
