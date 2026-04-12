#include<stdio.h>
int main(void)
{
	char a[10];
	scanf("%c",&a);
	if(a[0]=='a'||a[0]=='e'||a[0]=='i'||a[0]=='o'||a[0]=='u'){
		printf("vowel\n");
	}
	else{
		printf("consonant\n");
	}
	return 0;
}