#include <bits/stdc++.h>
char s[10];
int cnt=0;
int main()
{
	scanf("%s",s);
    for (int i=0;i<3;i++)
      if (s[i]=='A') cnt++;
    if (cnt!=3&&cnt!=0) puts("Yes");
    else puts("No");
	return 0;
}