#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int r,g,b;

int main(){
	cin>>r>>g>>b;
	if((g*10+b)%4==0){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}