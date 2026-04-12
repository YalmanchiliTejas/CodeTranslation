#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[]) {
	char c;
	scanf("%c", &c);
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') printf("vowel\n");
	else printf("consonant\n");

	return 0;
}
