#include<iostream>
#include<string>
using namespace std;


int main(){
	string str;
	cin >> str ;
	if(str.find("AC")!= std::string::npos)cout << "Yes"<< endl;
	else{
		cout << "No" << endl;
	}
}

