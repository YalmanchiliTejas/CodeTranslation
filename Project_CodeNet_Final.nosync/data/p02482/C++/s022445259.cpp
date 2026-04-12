#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	string str;
	getline(cin, str);
	int a,b;
	char c;
	istringstream is(str);
	is>>a>>b;

	if(a<b){
		cout<<"a < b"<<endl;
	}else if(a>b){
		cout<<"a > b"<<endl;
	}else{
		cout<<"a == b"<<endl;
	}

	return 0;
}