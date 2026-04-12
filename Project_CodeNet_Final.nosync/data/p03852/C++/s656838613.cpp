#include <bits/stdc++.h>
using namespace std;

int main() {
	char c;
	cin >> c;
	string result = "consonant";
	if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
		result = "vowel";
	}
	cout << result << endl;
}
