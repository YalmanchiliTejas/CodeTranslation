#include <stdio.h>
#include <string.h>
int main()
{
char str[100];
scanf("%s", str);
int a = 0, c = 0, i;
for(i = 0; i < strlen(str)-1;i++){
if(str[i] == 'A' && str[i+1] == 'C')
a = 1;
}
if(a)
printf("Yes\n");
else
printf("No\n");
return 0;
}