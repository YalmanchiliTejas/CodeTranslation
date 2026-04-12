#include <bits/stdc++.h>

using namespace std;

int main()
{
	char c;
	scanf("%c", &c);
	
	map<char, int> m;
	
	m['a'] = 1;
	m['e'] = 1;
	m['i'] = 1;
	m['o'] = 1;
	m['u'] = 1;
	
	if(m[c])
		printf("vowel\n");
	else
		printf("consonant\n");
	
	return 0;
}