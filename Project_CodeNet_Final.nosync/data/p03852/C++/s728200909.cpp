#include <iostream>
using namespace std;
int main(){
	string a;
	int f=0;
	cin >> a;
	if(a=="a")f=1;
	if(a=="e")f=1;
	if(a=="i")f=1;
	if(a=="o")f=1;
	if(a=="u")f=1;
	if(f==1){
		cout << "vowel" << endl;
	}else{
		cout << "consonant" << endl;
	}
	return 0;
}