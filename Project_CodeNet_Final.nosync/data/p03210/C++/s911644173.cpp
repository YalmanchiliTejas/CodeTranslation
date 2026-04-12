#include<iostream>
using namespace std;

int main() {
	int A;
	cin >> A;
	if (A == 3 || A == 5 || A == 7) {
		cout << "YES" << endl;
		return 0;
	}
	else {
		cout << "NO" << endl;
	}
}