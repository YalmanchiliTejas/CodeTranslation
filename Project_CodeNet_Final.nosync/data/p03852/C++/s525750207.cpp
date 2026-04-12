#include<stdio.h>
#include<iostream>
using namespace std;
int main(void)
{
		char a;
		int b, c;
	scanf("%c",&a);
	if(a=='a' || a=='i' || a=='u' || a=='e' || a=='o'){
			printf("vowel\n");
		}
	else{
			printf("consonant\n");
	}
	return 0;
}