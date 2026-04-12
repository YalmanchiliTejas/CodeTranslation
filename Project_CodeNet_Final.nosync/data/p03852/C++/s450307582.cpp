#include<stdio.h>
int main(void)
{
	char x;
	scanf("%c",&x);
	if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
		printf("vowel\n");
	}
	else{
		printf("consonant\n");
	}
	return 0;
}