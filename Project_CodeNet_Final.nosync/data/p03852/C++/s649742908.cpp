#include<stdio.h>
int main()
{
	char a[2];
	int f;
	
	scanf("%s",&a);
	if(a[0]=='a')puts("vowel");
	else if(a[0]=='e')puts("vowel");
	else if(a[0]=='i')puts("vowel");
	else if(a[0]=='u')puts("vowel");
	else if(a[0]=='o')puts("vowel");
	else puts("consonant");
	return 0;
}