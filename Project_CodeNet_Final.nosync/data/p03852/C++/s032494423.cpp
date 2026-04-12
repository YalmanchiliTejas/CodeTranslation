#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	char c; cin >> c;
	bool ok = false;
	if (c == 'a') ok = true;
	if (c == 'i') ok = true;
	if (c == 'u') ok = true;
	if (c == 'e') ok = true;
	if (c == 'o') ok = true;
	if(ok) cout << "vowel" << endl;
	else cout << "consonant" << endl;
	return 0;
}