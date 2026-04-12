#include<math.h>
#include<map>
#include<iostream>
#include <algorithm>
#include <string>
#include<vector>
#include<array>
#include<tuple>
#include<queue>
#include<stack>
#include<iomanip>
#include<bitset>
#include <list>
#include<numeric>
//AtCoderC++.cpp

using namespace std;

int main() {
	string s = "aiueo"; 
	char c; cin >> c;
	for (size_t i = 0; i < 5; i++) {
		if (c == s[i]) {
			cout << "vowel" << endl;
			return 0;
		}
	}
	cout << "consonant" << endl;
}