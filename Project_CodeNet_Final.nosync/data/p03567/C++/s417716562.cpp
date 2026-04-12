#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<cctype>
using namespace std;


int main() {
	string s;
	cin >> s;
	int c = s.size(), t = 0;
	for (int i = 0; i < c - 1; i++) {
		if (s[i] == 'A' && s[i + 1] == 'C')
			t = 1;
	}
	if (t == 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}