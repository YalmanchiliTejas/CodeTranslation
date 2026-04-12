#include <bits/stdc++.h>
using namespace std;

#define INF (INT64_MAX)
#define MOD (1000000000+7)
#define MAX 100000

int main() {
	char c;

	cin >> c;

	if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}

	return 0;
}
