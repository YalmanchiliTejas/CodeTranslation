#include<iostream>
using namespace std;

int main(void) {
	int x;
	cin >> x;
	cout << (x == 3 ? "YES" : (x == 5 ? "YES" : (x == 7 ? "YES" : "NO"))) << endl;
	return 0;
}