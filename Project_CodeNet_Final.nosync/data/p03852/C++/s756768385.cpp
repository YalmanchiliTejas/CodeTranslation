
// A - 居合を終え、青い絵を覆う

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const int MOD = 1e9 + 7;

int main() {
	char c;
	cin >> c;

	string ans;

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ans = "vowel";
	else ans = "consonant";

	cout << ans << endl;

	return 0;
}