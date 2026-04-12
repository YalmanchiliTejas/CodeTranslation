
#include <iostream>
using namespace std;

int main() {
	int flag=0;
	char c;cin>>c;
	if(c=='a')flag=1;
	if(c=='i')flag=1;
	if(c=='u')flag=1;
	if(c=='e')flag=1;
	if(c=='o')flag=1;
	if(flag){
		cout<<"vowel"<<endl;
	}else{
		cout<<"consonant"<<endl;
	}
	return 0;
}
