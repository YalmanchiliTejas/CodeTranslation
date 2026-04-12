#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int ma = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		int H;
		cin >> H;
		ma = max(ma, H);
		cnt += ma == H;
	}
	cout << cnt << endl;
	return 0;
}
