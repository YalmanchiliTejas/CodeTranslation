#include <iostream>
#include <vector>

using namespace std;

int main()
{
		int N;
		cin >> N;
		vector<int> H(N);
		for (int i = 0; i < N; i++) cin >> H[i];

		int cnt = 1;
		int maxH = H[0];
		for (int i = 0; i < N-1; i++) {
			if (H[i + 1] >= maxH) {
				maxH = H[i + 1];
				cnt++;
			}
		}
		cout << cnt << endl;
}