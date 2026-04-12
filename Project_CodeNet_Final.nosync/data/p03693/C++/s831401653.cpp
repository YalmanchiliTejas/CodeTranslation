#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int a,b,c;
	string s="NO";
	cin >> a; cin >> b; cin >> c;
	//a[0]==a[2]?cout << "Yes"<< endl: cout << "No" << endl;
	if ((a * 100 + b * 10 + c) % 4 == 0)s = "YES";
	cout << s << endl;
	
}