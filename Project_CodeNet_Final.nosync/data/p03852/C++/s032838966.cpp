#include <bits/stdc++.h>

using namespace std;

int main() {
  	char str;
    cin >> str;
    if (str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u') {
    	puts("vowel");
    } else {
    	puts("consonant");
    }
	return 0;
}