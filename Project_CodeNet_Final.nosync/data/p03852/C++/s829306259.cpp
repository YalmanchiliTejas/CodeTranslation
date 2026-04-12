#include<bits/stdc++.h>

using namespace std;

#define ll long long int

ll arr[(int)1e5 + 1];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char c; cin >> c;

	if(c == 'a' || c == 'u' || c == 'i' || c == 'e' || c == 'o')
		cout << "vowel\n";
	else cout << "consonant\n";

	return 0;
}