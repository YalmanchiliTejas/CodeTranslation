#include <cstdio>
char str[10];
int main()
{
scanf("%s",str);
int i;
for (i = 0; i < 4; i++)
if (str[i] == 'A' && str[i+1]=='C')
break;
if (i == 4)
printf("No\n");
else
printf("Yes\n");
return 0;}