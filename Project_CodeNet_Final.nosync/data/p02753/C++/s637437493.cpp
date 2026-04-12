#include <bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	cout << (int(s.find('A')) + int(s.find('B')) > 0 ? "Yes" : "No") << "\n";
}