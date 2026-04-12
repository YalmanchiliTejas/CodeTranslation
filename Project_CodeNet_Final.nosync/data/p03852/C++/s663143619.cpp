#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	char a;
	cin>>a;
	if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
	{
		printf("vowel\n");
	}
	else
	printf("consonant\n");
	return 0;
}