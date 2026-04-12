#include <bits/stdc++.h>

using namespace std;

int N;
map<long long int, int> DpSum;

int main() {
	int d, maxLen;
	long long int curSum;
	
	curSum = 0;
	maxLen = 0;
	DpSum[0] = 0;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> d;
		curSum += d;
		if (DpSum.count(curSum) == 0) {
			DpSum[curSum] = i;
			continue;
		}
		maxLen = max(maxLen, i - DpSum[curSum]);
	}
	cout << maxLen << endl;
	
	return 0;
}
