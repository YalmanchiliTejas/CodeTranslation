// 9132019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
long long a[1000000] = { 0 };
int ans = 0;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i >= 1) a[i] += a[i - 1];
	}
	map<long long,int>fmp;
	map<long long, int>gmp;
	for (int i = 0; i <= n; i++) {
		auto it = fmp.find(a[i]);
		if (it == fmp.end()) {
			fmp.insert(make_pair(a[i], i));
		}
	}
	for (int i = n; i >= 0; i--) {
		auto it = fmp.find(a[i]);
		if (it != fmp.end()) {
			ans = max(ans, i - it->second);
		}
	}
	cout << ans << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

