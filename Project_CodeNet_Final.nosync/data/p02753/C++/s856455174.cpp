#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	string s;
	getline(cin, s);
	if(s.empty()){
		getline(cin, s);
	}

	if(s[0] == s[1] and s[1] == s[2]){
		cout<<"No";
	}
	else cout<<"Yes";
	return 0;
}
