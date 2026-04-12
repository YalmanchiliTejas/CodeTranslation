#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>

typedef long long ll;

using namespace std;

int main() {
	char c;
	scanf("%c", &c);
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		printf("vowel\n");
	} else {
		printf("consonant\n");
	}
	
	return 0;
}