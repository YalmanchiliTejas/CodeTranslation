#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	string ans = "No";
	for (int i = 0;i < n - 1;i++) {
		if (s.substr(i, 2) == "AC") {
			ans = "Yes";
			break;
		}
	}
	cout << ans << endl;
}