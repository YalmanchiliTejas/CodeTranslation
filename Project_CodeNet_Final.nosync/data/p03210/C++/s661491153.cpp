#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void) {
	int d;
	cin >> d;
	cout << (d == 7 || d == 5 || d == 3 ? "YES" : "NO");
	return 0;
}