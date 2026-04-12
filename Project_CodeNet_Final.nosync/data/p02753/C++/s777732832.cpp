#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<sstream>
 
using namespace std;
 
string s;
string han;
 
string hantei(string* a) {
 
	if (*a == "AAA") {
      
		han = "No";
      
	}
	else {
		*a == "BBB" ? han = "No" : han = "Yes";
	}
 
	return han;
}
 
 
int main() {
 
	cin >> s;
 
	cout << hantei(&s) << endl;
 
	return 0;
 
}