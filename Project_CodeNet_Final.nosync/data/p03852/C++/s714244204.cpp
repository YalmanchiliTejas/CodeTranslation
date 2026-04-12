#include <bits/stdc++.h>
#define INF 2147483647
#define INF_LL 9223372036854775807
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	string c;
	cin >> c;
	if (c == "a" || c == "i" || c == "u" || c == "e" || c == "o") {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
}