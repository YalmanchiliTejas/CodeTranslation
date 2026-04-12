#include<iostream>
#include<string>
using namespace std;
int main(){
	string x;
	cin>>x;
	if(x=="a" || x=="i" || x=="u" || x=="e" || x=="o"){
		cout<<"vowel"<<endl;
	}else{
		cout<<"consonant"<<endl;
	}
	return 0;
}
