#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
using namespace std;

int main() {

	string S;
	cin >> S;

	if (S == "AAA" || S == "BBB") {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}

	return 0;
}
