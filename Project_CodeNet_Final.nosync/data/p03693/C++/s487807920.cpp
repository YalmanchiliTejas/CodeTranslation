#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int num[3];
	cin>>num[0]>>num[1]>>num[2];

	
	if((num[1]*10+num[2])%4==0){cout<<"YES"<<endl;}
	else{cout<<"NO"<<endl;}
	
	return 0;
}