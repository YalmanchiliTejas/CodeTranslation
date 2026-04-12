#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	string a;
	cin >> a;
	if(a.find("AC") != string::npos){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}