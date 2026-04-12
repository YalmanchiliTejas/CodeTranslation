#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <cstdint>
#include <istream>
#include <sstream>
#include <cctype>
#define fore(i,x,y) for(ll i=(x);i<(y);i++)
#define disp(a) cout << a << endl;
typedef long long ll;
using namespace std;

bool comp(const int& a, const int& b) {
	return a > b;
}

int main()
{
	string s;
	cin >> s;
	if (s=="AAA"||s=="BBB") {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}