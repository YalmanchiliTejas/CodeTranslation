#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;

	bool a = false, b = false;

	for(int i=0;i<3;++i){
		if(s[i] == 'A'){
			a = true;
		}
		else{
			b = true;
		}
	}

	cout << (a and b ? "Yes" : "No" ) << '\n';

	return 0;
}