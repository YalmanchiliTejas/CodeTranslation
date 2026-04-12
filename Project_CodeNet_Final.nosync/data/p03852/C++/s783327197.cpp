
#include<iostream> 

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	char s;
	cin >> s;
	if (s == 'a' || s == 'i' || s == 'u' || s == 'e' || s == 'o') {
		puts("vowel");
	}
	else {
		puts("consonant");
	}
	
	return 0;
}