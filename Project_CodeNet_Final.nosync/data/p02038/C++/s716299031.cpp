#include<iostream>
using namespace std;
int main() {
	int n; cin >> n;
	char a, b; cin >> a;
	for (int i = 1; i < n; i++) {
		cin >> b;
		a = (a == 'T'&&b == 'F' ? 'F' : 'T');
	}
	cout << a << endl;
}
