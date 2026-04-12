#include <iostream>
#include <string>
using namespace std;

int main() {
	char s[3];
	int flag=0;
	for(int i=0;i<3;i++){
		cin>>s[i];
		if(s[0]!=s[i]){
			flag=1;
		}
	}
	if(flag==0){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
	// your code goes here
	return 0;
}