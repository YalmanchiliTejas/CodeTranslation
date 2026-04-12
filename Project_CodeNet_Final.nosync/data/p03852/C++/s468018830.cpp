#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	char c;
	scanf("%c",&c);
	if((c=='a')||(c=='i')||(c=='u')||(c=='e')||(c=='o')){
		printf("vowel");
	}else{
		printf("consonant");
	}
    return 0;
}
 