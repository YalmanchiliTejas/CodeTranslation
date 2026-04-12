#include<iostream>
#include<cstdio>
using namespace std;
char x;
int main()
{
	cin>>x;
	if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u')printf("vowel");else printf("consonant");
	return 0;
}