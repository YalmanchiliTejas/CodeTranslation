#include <iostream>

using namespace std;
int main(void){
	string v = "aeiou";
	char c;
	cin >> c;
	bool res = 0;
	for(char a : v){
		if(a==c)res=1;
	}
	if(res)	cout << "vowel" << endl;
	else cout << "consonant" << endl;
}