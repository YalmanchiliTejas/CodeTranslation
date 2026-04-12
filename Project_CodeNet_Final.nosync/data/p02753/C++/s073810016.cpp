#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string S,ans;
	cin >> S;
	if (S[0] != S[1] || S[1] != S[2]) {
		ans = "Yes";
	}
	else {
		ans = "No";
	}
	cout << ans << endl;
	return 0;
}