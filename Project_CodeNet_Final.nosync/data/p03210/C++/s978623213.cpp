#include<iostream>
#include<string>
using namespace std;
int main() {
	int x; cin >> x;
	string ans;
	if (x == 7) { ans = "YES"; }
	else if (x == 5) { ans = "YES"; }
	else if (x == 3) { ans = "YES"; }
	else { ans = "NO"; }
	cout << ans << endl;
	return 0;
}