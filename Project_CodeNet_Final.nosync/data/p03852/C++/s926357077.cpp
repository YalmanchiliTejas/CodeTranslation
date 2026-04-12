#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include <vector>

typedef long long ll;
using namespace std;



int main()
{
	char c;
	scanf("%c", &c);

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		printf("vowel\n");
	}
	else {
		printf("consonant\n");
	}
	
	return 0;
}
