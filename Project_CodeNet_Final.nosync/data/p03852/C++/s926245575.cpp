#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
	char c;
	cin >> c;
	if (vowels.find(c) == vowels.end()) {
		cout << "consonant\n";
	} else {
		cout << "vowel\n";
	}
	

	return 0;
}

