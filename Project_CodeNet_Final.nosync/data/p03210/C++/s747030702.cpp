#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	int x;
	string ans;
	cin >> x;
	if (x == 3||x== 5||x== 7) {
		ans = "YES";
	}
	else {
		ans = "NO";
	}

	cout << ans << endl;

	return 0;
}