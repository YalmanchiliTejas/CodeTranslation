#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
	int n;
	cin >> n;
	int maxi;
	cin >> maxi;
	int count = 1;
	for (int i = 1; i < n; i++) {
		int temp;
		cin >> temp;
		if (maxi <= temp) {
			count++;
			maxi = max(maxi, temp);
		}
	}
	cout << count << endl;
	return 0;
}