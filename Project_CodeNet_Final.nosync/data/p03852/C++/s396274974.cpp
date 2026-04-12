#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	char c,a = 'a',e = 'e',i = 'i',o = 'o',u = 'u';
	scanf("%c",&c);
	if(c == a||c == e||c == i||c == o||c == u)
		printf("vowel");
	else printf("consonant");
	return 0;
}