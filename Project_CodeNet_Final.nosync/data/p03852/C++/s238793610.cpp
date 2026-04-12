#include <cstdio>
#include <iostream>
using namespace std;
int main()

{
	char n;
	cin>>n;
	if(n=='a'||n=='e'||n=='i'||n=='o'||n=='u') printf("vowel");
	else printf("consonant");
	return 0;
}