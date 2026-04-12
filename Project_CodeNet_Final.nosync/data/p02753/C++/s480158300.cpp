#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string S;
	cin >> S;

	string ans = "Yes\n";
	if (S[0] == S[1] && S[1] == S[2] && S[2] == S[0])
		ans = "No\n";

	cout << ans;
	return 0;
}
