
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int a,b;
	string func;
	
	cin>>a>>b;

	if(a < b){
		func = "a < b";
	}
	if(a > b){
		func = "a > b";
	}
		
	if(a == b){
		func = "a == b";
	}

	cout<<func<<endl;

	return 0;
}