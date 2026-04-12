#include <bits/stdc++.h>
using namespace std;

void solve(string c){
	if (c == "a" or c == "e" or c == "i" or c == "o" or c == "u") {
		cout << "vowel" << endl;	
	} else {
		cout << "consonant" << endl;
	}	
}

int main(){	
	string c;
	cin >> c;
	solve(c);
	return 0;
}

