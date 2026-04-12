#include <bits/stdc++.h>
using namespace std;

const string s = "aeiou";

int main(){

	char c;
	scanf("%c", &c);

	int f = s.find(c);

	string ans = f != string::npos ? "vowel" : "consonant";

	cout << ans << '\n';

	return 0;
}