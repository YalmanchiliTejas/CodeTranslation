#include<iostream>
using namespace std;

int main(){
	char c;
	cin >> c;
	int flag =0;

	if(c == 'a') flag=1;
	if(c == 'i') flag=1;
	if(c == 'u') flag=1;
	if(c == 'e') flag=1;
	if(c == 'o') flag=1;

	if(flag == 1)cout << "vowel"<<endl;
	else cout<<"consonant"<<endl;
}