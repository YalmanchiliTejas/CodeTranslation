#include<bits/stdc++.h>
#define at putchar('\n')
using namespace std;
int main(void)
{
	switch(getchar())
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':puts("vowel");break;
		default:puts("consonant");
	}
    return 0;
}