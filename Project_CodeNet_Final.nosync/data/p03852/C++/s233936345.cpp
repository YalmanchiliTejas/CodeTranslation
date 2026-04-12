#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	char a;
	cin >> a;
	char s[5] = {'a', 'i', 'u', 'e', 'o'};
	char * p = find(s, s+5, a);
	if(p == s+5) cout << "consonant" << endl;
	else cout << "vowel" << endl;
	return 0;
}