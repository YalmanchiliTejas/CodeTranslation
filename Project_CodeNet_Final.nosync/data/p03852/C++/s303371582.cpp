#include <iostream>
using namespace std;
int main(void){
	char a;
	cin >> a;
	if(a == 'a' || a == 'e'||  a == 'i' ||  a == 'o' ||  a == 'u'){
		cout << "vowel" << endl;
		return 0;
	}
	else{
		cout << "consonant" << endl;
	}
}