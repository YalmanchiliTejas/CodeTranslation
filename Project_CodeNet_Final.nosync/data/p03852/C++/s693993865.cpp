#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
	int a,s,d;
	char z[2];
	scanf("%s",z);
	if(z[0]=='a'||z[0]=='i'||z[0]=='u'||z[0]=='e'||z[0]=='o')
		printf("vowel\n");
	else
		printf("consonant\n");
	return 0;
}