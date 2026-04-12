#include <iostream>
using namespace std;

int r, g, b, angkatest;

int main (){
	cin>>r>>g>>b;
	angkatest=r*100+g*10+b;
	if (angkatest%4==0){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}