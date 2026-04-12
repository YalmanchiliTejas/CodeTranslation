#include <iostream>
#include <cstdio>
using namespace std;

string a;
int main() {
	cin >> a;
	cout << (a=="AAA" || a=="BBB" ? "No" : "Yes");
	return 0;
}