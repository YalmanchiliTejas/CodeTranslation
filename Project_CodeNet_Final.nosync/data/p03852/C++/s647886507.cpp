#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<tuple>
#define int long 
using namespace std;

signed main() {
	char A;
	cin >> A;
	if(A == 'a' || A == 'i' || A == 'u' || A == 'e' || A == 'o') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
}