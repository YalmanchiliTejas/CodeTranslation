#define _USE_MATH_DEFINES
#include<stdio.h>
#include<string>
#include<iostream>
#include<cctype>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<iomanip>
#include<functional>
using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	string c; cin >> c;
	if (c == "a" || c == "i" || c == "u" || c == "e" || c == "o") {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
	return EXIT_SUCCESS;
}