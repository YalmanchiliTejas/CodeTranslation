#include <iostream>
using namespace std;

int main() {
	char alphabet;
	scanf("%c", &alphabet);
	
	if (alphabet == 'a' || alphabet == 'e' || alphabet == 'i' || alphabet == 'o' || alphabet == 'u') printf("vowel");
	else printf("consonant");
	return 0;
}