#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(void) {
	int x;
	cin >> x;
	if (x == 3 || x == 5 || x == 7) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}