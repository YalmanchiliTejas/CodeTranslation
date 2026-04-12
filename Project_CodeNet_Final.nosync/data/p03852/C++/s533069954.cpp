#include <bits/stdc++.h>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);++i)

using namespace std;

int main () {
	string s; cin >> s;
	if (s[0] == 'a') cout << "vowel" << '\n';
	else if (s[0] == 'i') cout << "vowel" << '\n';
	else if (s[0] == 'u') cout << "vowel" << '\n';
	else if (s[0] == 'e') cout << "vowel" << '\n';
	else if (s[0] == 'o') cout << "vowel" << '\n';
	else cout << "consonant" << '\n'; 

	return 0;

}