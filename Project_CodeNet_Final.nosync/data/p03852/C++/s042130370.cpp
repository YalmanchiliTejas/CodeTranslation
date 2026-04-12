#include<stdio.h>
int main(void)
{
	char s;
	scanf("%c",&s);
	if(s=='a' || s=='e'	|| s=='i' || s=='o' || s=='u')
	{   
			printf("vowel\n");
	}
	else{
		printf("consonant\n");
	}
	return 0;
}