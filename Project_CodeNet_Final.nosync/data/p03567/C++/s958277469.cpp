#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string str;

	cin>>str;

	if((int)str.find("AC")>=0){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}

}