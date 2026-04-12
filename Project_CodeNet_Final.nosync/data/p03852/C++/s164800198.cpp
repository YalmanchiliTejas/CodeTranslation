#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s;
	cin>>s;
	if(s=="a"||s=="e"||s=="i"||s=="o"||s=="u"){
		cout<<"vowel";
	}else{
		cout<<"consonant";
	}

}