#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include <stdio.h>
using namespace std;

int main() {
	int n, k;
	string s;
	char sm;
	cin >>n >> s >>k ;
	sm = s[k-1];
	for (int i = 0; i < n; i++) {
		if (s[i] != sm) {
			s[i] = '*';
		}
	}
	cout << s << endl;

	
	
}