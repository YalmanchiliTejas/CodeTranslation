#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int res = 0;
	int H = 0;
	for (int i = 0; i < n; i++) {
		if (h[i] >= H) {
			res++;
			H = h[i];
		}
	}
	cout << res << endl;
}