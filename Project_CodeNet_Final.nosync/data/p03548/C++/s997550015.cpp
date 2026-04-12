#include <iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include <stdio.h>

using namespace std;

int main() {
 
	int a, b, c;
	cin >> a >> b >> c;
	b = b + c;
	a = a - c;
	a = a / b;
	cout << a << endl;

	return 0;
}