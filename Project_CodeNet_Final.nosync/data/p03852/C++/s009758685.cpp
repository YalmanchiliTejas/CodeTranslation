#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	char c; cin >> c;
	
	string ans = "consonant";

	if (c == 'a') ans = "vowel";
	if (c == 'e') ans = "vowel";
	if (c == 'i') ans = "vowel";
	if (c == 'o') ans = "vowel";
	if (c == 'u') ans = "vowel";

	cout << ans << endl;
	return 0;
}