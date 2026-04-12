#include<stdio.h>
int main()
{
	char s[3],ch;
	int i,count=0;
	scanf("%s",s);
	ch=s[0];
	for(i=1;i<3;i++)
	{
		if(s[i]==ch)
		count++;
	}
	if(count==2)
	printf("No\n");
	else
	printf("Yes\n");
	return 0;
}