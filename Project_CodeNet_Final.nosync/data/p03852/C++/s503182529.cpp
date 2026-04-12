#include <bits/stdc++.h>

using namespace std;

int main(){
	char c[2];
	scanf("%s", c);
	if (c[0] == 'a' || c[0] == 'e'|| c[0] == 'i'|| c[0] == 'o' || c[0] == 'u')
		puts("vowel");
	else 
		puts("consonant");
	return 0;
}
