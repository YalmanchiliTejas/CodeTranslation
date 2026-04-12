#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;
 
int main(void){
	
	char c;
	
	cin >> c;
	
	if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
		cout << "vowel";
	else
		cout << "consonant";
	
	return 0;
}