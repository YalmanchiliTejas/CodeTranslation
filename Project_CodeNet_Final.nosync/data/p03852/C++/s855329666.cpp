#include <iostream>

using namespace std;

int main(){
	char c;
	cin>>c;
	for(int i = 0; i < 5; i++){
		if("aiueo"[i] == c){
			cout<<"vowel"<<endl;
			return 0;
		}
	}
	cout<<"consonant"<<endl;
}