#include<bits/stdc++.h>
using namespace std;

int main(){
	bool ok=false;
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='a'||s[i]=='i'||s[i]=='u'||s[i]=='e'||s[i]=='o') ok=true;
	}
	cout << (ok?"vowel":"consonant") << endl;
	return 0;
}