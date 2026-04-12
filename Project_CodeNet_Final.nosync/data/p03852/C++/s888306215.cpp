#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	//int num;
	
	cin >> str;	
	if(str.at(0)=='a' || 
			str.at(0)=='i' || 
			str.at(0)=='u' || 
			str.at(0)=='e' || 
			str.at(0)=='o' ){
				cout << "vowel" << endl;
				
			}else{
				cout << "consonant" << endl;
				
			}
	return 0;
}