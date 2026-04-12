#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s;
	int k;
	cin >> n >> s >> k;
	k--;
	for(int i = 0; i < n; i++){
		if(s[k] != s[i]){
			cout << "*" ;
		}else{
			cout << s[i];
		}
	}
	cout << endl;
	
	// your code goes here
	return 0;
}
