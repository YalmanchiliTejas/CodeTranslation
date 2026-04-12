#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char ca[10];
	cin>>ca;
	for(int i=0;i<strlen(ca)-1;i++){
		if(ca[i]=='A' && ca[i+1]=='C'){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}
	
