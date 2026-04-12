#include <iostream>
#include <string>


using namespace std;

int main() {
	string inp;
	cin>>inp;
	if (inp[0]!=inp[1]){
		cout<<"Yes"<<endl;
	}else if(inp[0]!=inp[2]){
		cout<<"Yes"<<endl;
	}else {cout<<"No"<<endl;}
	return 0;
}