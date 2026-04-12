#include <iostream>
using namespace std;

int a[200001];
int tmp[200001];

int main() {
	int n;
	cin >> n;

	int start = 0;
	int end = n -1;

	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		tmp[i] = b;
	}

	for (int i = 0; i < n; i++) {
		int cur = tmp[n - i - 1];
		if (i % 2 == 0) {
			a[start] = cur;
			start++;
		} else {
			a[end] = cur;
			end--;
		}
	}


	for (int i = 0; i < n; i++) {
		int b;
		cout << a[i] << " ";
	}

	cout << endl;

	return 0;

}