#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	char c;
	cin >> c;
	if (c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u') {
		cout << "vowel";
	}
	else cout << "consonant";
}