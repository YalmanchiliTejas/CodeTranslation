#include<stdio.h>
int main(void)
{
	int c;
	scanf("%c",&c);
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
		printf("vowel\n");
	}
	else{
		printf("consonant\n");
	}
	return 0;
}