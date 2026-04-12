#include <bits/stdc++.h>
using namespace std;
int main(){
	char a;
	
	cin >> a;
	if(a == 'a' || a == 'o' || a == 'u' || a == 'e' || a == 'i'){
		cout << "vowel";
		return 0;
	}
	
	cout << "consonant";
	return 0;
}
