#include<iostream>

using namespace std;

int main(){
	int r;
	int g;
	int b;

	cin>>r>>g>>b;

	int n=g*10+b;

	if(n%4==0){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}