#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	char c;
	cin>>c;
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
	{
		printf("vowel\n");
	} 
	else
	{
		printf("consonant\n");
	}
	return 0;
} 