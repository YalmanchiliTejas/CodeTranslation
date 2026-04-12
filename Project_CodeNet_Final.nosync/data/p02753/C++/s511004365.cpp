#include <bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	cout << (s.find('A') + s.find('B') > 3 ? "No" : "Yes");
}