#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<int> h(n);
	for (int& h_s : h) {
		cin >> h_s;
	}
	int max = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (h[i] >= max) {
			count++;
			max = h[i];
		}
	}
	cout << count;
}