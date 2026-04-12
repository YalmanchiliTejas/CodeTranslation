#include <iostream>
#include<string>
 
using namespace std;
 
 
 
int main() {
	string input;
	cin >> input;
 
	auto result_a = input.find("AAA");
	auto result_b = input.find("BBB");
 
	if (result_a == string::npos && result_b == string::npos) cout << "Yes" << endl;
	else cout << "No" << endl;
 
	return 0;
}