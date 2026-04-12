#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int H[n];
	for(int i = 0; i < n; i++){
		cin >> H[i];
	}
	
	int minHeight = H[0];
	int cnt = 0;

	for (int i = 0; i < n; i++) {

		if (minHeight <= H[i])
		{
			minHeight = H[i];
			cnt++;
		}
	}
	cout << cnt << endl;
}
