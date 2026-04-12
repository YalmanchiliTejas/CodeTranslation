#include <bits/stdc++.h>


using namespace std;

int main() {

	string s;
	cin >> s;
	bool check=false;
	for(int i=0;i<s.length();i++){
		if(s[i]=='A')
			check=true;
		else if(check and s[i]=='C')
			break;
		else
			check=false;
		if(i==s.length()-1)
			check=false;

	}
	if(check)
		cout << "Yes";
	else
		cout << "No";
}