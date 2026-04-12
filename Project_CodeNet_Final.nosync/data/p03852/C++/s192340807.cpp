#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char al;
	scanf("%c", &al);
	if(al == 'a' || al == 'e' || al == 'i' || al == 'o' || al == 'u')
		printf("vowel\n");
		else
			printf("consonant\n");
}