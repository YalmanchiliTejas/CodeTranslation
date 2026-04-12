#include<iostream>
using namespace std;

int main(void){
	char c;
	string str="aiueo";

	cin >> c;
	
	for(int i=0;i<5;i++){
		if(str[i]==c){
			cout << "vowel" << endl;
			return 0;
		}
	}

	cout << "consonant" << endl;
	
	return 0;
}
