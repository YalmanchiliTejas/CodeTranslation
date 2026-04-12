#include <iostream>
using namespace std;

int main()
{
	int n;
	int a[100];
		
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		int max = 0;
		int min = 1000;
		int total = 0;
		int answer = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			total += a[i];
			if (a[i] > max) {
				max = a[i];
			}
			if (a[i] < min) {
				min = a[i];
			}
		}
		answer = (total - max - min) / (n - 2);
		cout << answer << endl;
	}
	return 0;
}