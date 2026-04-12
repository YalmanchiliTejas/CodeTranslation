#include<iostream>
#include<cstdio>
using namespace std;
char a; 
int main()
{
	scanf("%c",&a);
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') printf("vowel");
	else printf("consonant");
	return 0;
}