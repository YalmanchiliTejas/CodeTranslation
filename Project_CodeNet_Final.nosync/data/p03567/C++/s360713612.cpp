#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <iomanip>
#include <math.h> 

using namespace std;

int main() {
	string str;

	cin >> str;

	if (str.find("AC") != std::string::npos) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}





	return 0;
}