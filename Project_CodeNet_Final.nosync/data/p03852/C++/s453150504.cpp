#include <bits/stdc++.h>
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

int main() {
	char a; scanf("%c", &a);
	
	if(a == 'a' or a == 'e' or a == 'i' or a == 'u' or a == 'o') printf("vowel\n");
	else printf("consonant\n");
	return 0;
}
