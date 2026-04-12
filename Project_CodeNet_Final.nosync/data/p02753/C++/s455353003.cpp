#include <iostream>
#include<string>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<map>
using namespace std;


int main() {
	int i = 0;
	string S;
	cin >> S;

	if (S[0] != S[1]) {
		i = 1;
	}
	if (S[1] != S[2]) {
		i = 1;
	}

	if (i == 1) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}