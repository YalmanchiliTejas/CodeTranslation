#include<bits/stdc++.h>
using namespace std;
char c;
int main() {
	ios::sync_with_stdio(false);
	cin >> c;
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		cout << "vowel\n";
	else
		cout << "consonant\n";
	return 0;
}