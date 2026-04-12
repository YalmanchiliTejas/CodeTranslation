#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int llint;
int main() {
	int n;
	cin >> n;
	if (n == 3 || n == 5 || n == 7) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}