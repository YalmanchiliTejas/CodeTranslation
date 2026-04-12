#include <iostream>
using namespace std;
char a[5]={'a','e','i','o','u'},b;
int main(){
	cin>>b;
	for(int i=0;i<5;i++){
		if(b==a[i]){
			cout<<"vowel"<<endl;return 0;
		}
	}
	cout<<"consonant"<<endl;
	return 0;
} 