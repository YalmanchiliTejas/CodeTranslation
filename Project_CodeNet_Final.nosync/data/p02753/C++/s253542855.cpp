#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	set <char> s2;
	for (char c : s) s2.insert(c);
	cout << (s2.size() == 1 ? "No" : "Yes") << "\n";
	return 0;
}
