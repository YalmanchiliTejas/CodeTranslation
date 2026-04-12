#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}


int main() {
	char c; cin >> c;
	string s = "aiueo";
	for (int i = 0; i < 5; i++) {
		if (s.at(i) == c) {
			cout << "vowel" << endl;
			return 0;
		}
	}
	cout << "consonant" << endl;
	return 0;
}