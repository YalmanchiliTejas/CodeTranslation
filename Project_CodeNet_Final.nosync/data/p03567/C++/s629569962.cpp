#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
int main() {
	string s; cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s.substr(i, 2) == "AC") {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n"; return 0;
}