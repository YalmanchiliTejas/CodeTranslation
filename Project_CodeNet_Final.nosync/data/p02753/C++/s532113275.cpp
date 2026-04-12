#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

string S;

int main(void) {

	cin >> S;

	if (S == "AAA" || S == "BBB") { cout << "No" << endl; }
	else { cout << "Yes" << endl; }

	return 0;
}