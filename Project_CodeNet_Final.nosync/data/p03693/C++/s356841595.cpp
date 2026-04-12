#include<iostream>

using namespace std;

int r,g,d; 

int main(){
	cin>>r>>g>>d;
	if((r*100+g*10+d)%4==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

	return 0;
}