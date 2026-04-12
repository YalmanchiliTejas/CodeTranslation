#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int i,n=s.size();
	for(i=0; i<n-1; i++){
		if(s[i]=='A' && s[i+1]=='C'){
			cout << "Yes"; return 0;
		}
	}
	cout << "No"; 
	return 0;
}