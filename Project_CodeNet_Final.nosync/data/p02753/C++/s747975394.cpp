#include<bits/stdc++.h>
 
using namespace std;
 
 
 
int main() {
	
	ios_base :: sync_with_stdio(0); cin.tie(NULL);
 
	string s;
	cin >> s;
 
	bool A = false, B = false;
	for(int i = 0; i < s.length(); ++i) {
		if (s[i] == 'A') A = true;
		else if(s[i] == 'B') B = true;
	}
 
	if (A && B) cout << "Yes" << '\n';
	else cout << "No" << '\n';
 
	return 0;	
}