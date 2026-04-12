#include<iostream>
#include<string.h>
using namespace std;
char a[5];
int main(){
	cin>>a;
	int len=strlen(a);
	bool ff=false,f=false;
	for(int i=0;i<len;i++){
		if(a[i]=='A'){
			f=true;
		}
		if(a[i]=='B'){
			ff=true;
		}
	}
	if(ff && f){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}