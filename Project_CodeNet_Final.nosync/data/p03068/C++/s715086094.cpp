#include<stdio.h>
int main()
{
  int n,m,i;
  char s[1000];

scanf("%d",&n);
scanf("%s",s);
scanf("%d",&m);
for(i=0;i<n;i++)
{
  if(s[i]!=s[m-1])
	  s[i]='*';
}
for(i=0;i<n;i++)
{
printf("%c",s[i]);
}
printf("\n");
return 0;
}