#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
using namespace std;

int main(void)
{
	int N;
	cin >> N;

	vector<int> H(N);
	for (int i = 0; i < N; i++)
		cin >> H[i];

	int ans = 0;
	int h = 0;
	for (int i = 0; i < N; i++) {
		if (H[i] >= h) {
			ans++;
			h = H[i];
		}
	}

	cout << ans << endl;

	return 0;
}
