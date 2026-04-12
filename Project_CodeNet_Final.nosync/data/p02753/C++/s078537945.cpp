/*
@author: sharrad99
*/
#include<bits/stdc++.h>
using namespace std;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	bool a = false, b = false;
	for(int i = 0; i < 3; i++) {
		a |= s[i] == 'A';
		b |= s[i] == 'B';
	}

	cout << (a and b ? "Yes\n" : "No\n");
}