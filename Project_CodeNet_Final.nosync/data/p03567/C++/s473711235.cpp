#include<bits/stdc++.h>
using namespace std;



int main(){
	bool ok = false;
	string s;
	cin >> s;
	for(int i=1;i<s.size();i++){
		if(s[i]=='C'&&s[i-1]=='A') ok=true;
	}
	cout << (ok?"Yes":"No") << endl;
	return 0;
}