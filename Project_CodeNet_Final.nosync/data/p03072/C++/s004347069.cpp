#include<iostream>

int main() {
	using namespace std;
	int n, max, num,count = 1;
	cin >> n;
	cin >> max;
	for (int i = 1; i < n; i++) {
		cin >> num;
		if (num >= max) {
			max = num;
			count++;
		}

	}
	cout << count << endl;
}