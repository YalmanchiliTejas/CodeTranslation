#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	bool ok = n == m;
	if(ok)
		cout << "Yes";
	else
		cout << "No";
}