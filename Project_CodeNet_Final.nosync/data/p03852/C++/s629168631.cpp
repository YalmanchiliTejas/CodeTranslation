#include <bits/stdc++.h>
using namespace std;

int main(void){
	char c[2];
	cin >> c;
	if(c[0]=='a' || c[0]=='i'||c[0]=='e'||c[0]=='u'||c[0]=='o'){
		cout << "vowel";
	}else{
		cout << "consonant";
	}
	return 0;
}