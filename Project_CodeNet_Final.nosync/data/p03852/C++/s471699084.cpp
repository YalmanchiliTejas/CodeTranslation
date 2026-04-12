#include <bits/stdc++.h>
using namespace std;

 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	char ch;
	cin >> ch;

	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
		cout << "vowel\n";
	}
	else {
		cout << "consonant\n";
	}
 
	return 0;
}