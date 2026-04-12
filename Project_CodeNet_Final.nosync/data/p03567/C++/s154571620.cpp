#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<iostream>
#include<iostream>
#include<cctype>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include <algorithm>
#include<math.h>
#include<set>
#include<map>
#include <sstream>
#include<iomanip>
#include <ctype.h>
using namespace std;

//#include<bits/stdc++.h>


int main() {
	
	string p;
	cin >> p;

	for (int i = 0; i < p.size() - 1; i++) {
		string h = p.substr(i, 2);
		if (h == "AC" ) {
			cout << "Yes" << endl; return 0;
		}
	}
	cout << "No" << endl;

	return 0;
}