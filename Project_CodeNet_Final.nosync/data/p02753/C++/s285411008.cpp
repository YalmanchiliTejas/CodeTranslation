#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	sort(s.begin(), s.end());

	cout << ((s[0] != s[2]) ? "Yes" : "No") << endl;
}