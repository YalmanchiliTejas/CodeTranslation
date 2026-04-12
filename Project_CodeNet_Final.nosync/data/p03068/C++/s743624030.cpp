#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

int main()
{
	int n, k;
	string s;
	cin >> n >> s >> k;
	for (int i = 0; i < n; i++) {
		if (s.at(i) != s.at(k - 1)) {
			s.at(i) = '*';
		}
	}
	cout << s << endl;
}