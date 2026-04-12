#include <bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	cout << (s.find('A') != -1 and s.find('B') != -1 ? "Yes" : "No");
}