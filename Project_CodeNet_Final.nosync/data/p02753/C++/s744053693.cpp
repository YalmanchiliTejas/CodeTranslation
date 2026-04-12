#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;
double condition = 0.0;
void func()
{
	string S;
	cin >> S;
	if(S.find('A') != std::string::npos
		&& S.find('B') != std::string::npos)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main() {
//	while(1)
	func();
	return 0;
}
