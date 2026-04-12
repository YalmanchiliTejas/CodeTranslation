#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <ctype.h>
#include <stdlib.h>
#include <map>
using namespace std;

int main()
{
	string S;
	cin >> S;
	if (S[0] == S[1] && S[1] == S[2]) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}

}


