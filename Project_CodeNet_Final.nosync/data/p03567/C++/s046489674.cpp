#include <iostream>
#include <algorithm>
#include <string> 
#include <vector>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

int main()
{
	string S;
	cin >> S;
	bool can = false;
	for (int i = 0; i < S.size() - 1; i++) {
		if (S[i] == 'A' && S[i + 1] == 'C') {
			can = true;
		}
	}
	if (can) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}