#include<bits/stdc++.h>
using namespace std;
int main(){
	string s; cin >> s;
	regex po("(a|i|u|e|o)");
	cout << (regex_match(s, po) ? "vowel\n" : "consonant\n");
	return 0;
}