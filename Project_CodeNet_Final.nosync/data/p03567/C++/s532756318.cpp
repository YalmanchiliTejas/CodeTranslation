#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s; cin >> s;
	for(int i = 0; i < s.size() - 1; i++) {
		if(s.substr(i, 2) == "AC") {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
		
	return 0;                                              
}
	
