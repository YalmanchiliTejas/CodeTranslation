#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<limits.h>
#include<vector>
#include<tuple>
using namespace std;
int main() {
	
	char x, y, z;
	cin >> x >> y >> z;
		
	if (x == y && y == z) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	return 0;

}