#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	char a, b, c;
	cin >> a >> b >> c;
	if (a == b && b == c) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	return 0;
}