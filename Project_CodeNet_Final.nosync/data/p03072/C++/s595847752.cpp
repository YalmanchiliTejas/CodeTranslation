#include <iostream>
using namespace std;
int main()
{
	int n;
	int h[30];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int count = 1;
	for (int i = 1; i < n; i++) {
		bool ch = true;
		for (int j = 0; j < i ; j++) {
			if (h[j] > h[i]) { ch = false; }
		}
		if (ch) { count++; }
	}
	cout << count << endl;
	return 0;
}