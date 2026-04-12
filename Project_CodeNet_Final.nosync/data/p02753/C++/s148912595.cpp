#include <bits/stdc++.h> 

using namespace std; 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	if(s[0] == s[1] and s[2] == s[0]) {
		cout << "No\n";
	}
	else cout << "Yes\n";


	return 0;
}
