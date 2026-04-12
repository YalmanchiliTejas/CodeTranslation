#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

long long N;
int main() {
	string S;
	cin >> S;
	for (int i = 0; i < S.length()-1; i++) {
		if (S[i] == 'A' && S[i + 1] == 'C') {
			cout << "Yes";
			return  0;
		}

	}
	cout << "No";
	return 0;



	return 0;
}
