#include <iostream>
#include <cstdio>
using namespace std;

char c;
int main() {
	cin >> c;
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') puts("vowel");
	else puts("consonant");
	return 0;
}
