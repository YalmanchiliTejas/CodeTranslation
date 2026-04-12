#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <climits>
#include <vector>
using namespace std;

#define ll long long int

const int MOD = 1000000007;

int max(int a, int b) {

	if (a > b)return a;
	else return b;

}
int main() {

	char c;

	cin >> c;

	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {

		cout << "vowel" << endl;

	}
	else {

		cout << "consonant" << endl;

	}

	return 0;
}