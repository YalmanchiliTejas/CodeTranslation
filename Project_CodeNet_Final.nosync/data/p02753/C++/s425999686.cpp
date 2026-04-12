#include<iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main(void) {
	char n[4];
	bool flag = true;
	cin >> n;
	
	if(n[0] == n[1] && n[1] == n[2] && n[2] == n[0])cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}