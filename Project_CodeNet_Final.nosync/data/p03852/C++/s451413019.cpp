#include<iostream>
using namespace std;
int main(){
	char a[5][3]={ "a", "e", "i", "o", "u"};
	string s;
	cin>>s;
	for(int i=0;i<5;i++){
		if(a[i]==s) {
			cout<<"vowel"<<endl;
			return 0;
		}
	}
	cout<<"consonant"<<endl;
	return 0;
} 