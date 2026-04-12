#include<iostream>
#include<cstdio>
using namespace std;
char c;
int main()
{
	cin>>c;
	switch(c)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u': puts("vowel"); break;
		default: puts("consonant");
	}
	return 0;
}