#include<iostream>
#include<string>
using namespace std; 
int main(void){ 
	string a;
	cin >> a;
	if (a == "AAA" || a == "BBB"){
		cout << "No";
	}else{
		cout << "Yes";
	}
	 return 0;
}