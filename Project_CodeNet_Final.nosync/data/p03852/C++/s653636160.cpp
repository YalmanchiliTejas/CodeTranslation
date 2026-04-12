#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	char x; cin >> x;
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') cout << "vowel\n";
	else cout << "consonant\n";
	
	return 0;
}
