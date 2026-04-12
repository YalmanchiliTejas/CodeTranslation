#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
signed main() {
	string s; cin >>s>> s;
	int r; cin >> r;
	for (int i = 0; i < s.size(); i++) {
		cout << (s[i] == s[r - 1] ? s[i] : '*');
	}
	cout << endl;
}