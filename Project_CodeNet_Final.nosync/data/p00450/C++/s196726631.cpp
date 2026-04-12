#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> StonesInfo[100000];

int main() {
	int num, curPos, sum;
	
	while (cin >> N, N) {
		cin >> num;
		StonesInfo[0] = { num,1 };
		curPos = 0;
		for (int i = 2; i <= N; ++i) {
			cin >> num;
			if ((i & 1) == 1) {
				if (StonesInfo[curPos].first == num) {
					++StonesInfo[curPos].second;
				}
				else {
					++curPos;
					StonesInfo[curPos] = { num,1 };
				}
				continue;
			}

			if (StonesInfo[curPos].first == num) {
				++StonesInfo[curPos].second;
				continue;
			}
			if (curPos == 0) {
				StonesInfo[curPos].first = num;
				++StonesInfo[curPos].second;
			}
			else {
				StonesInfo[curPos - 1].second += StonesInfo[curPos].second + 1;
				--curPos;
			}
		}
		sum = 0;
		for (int i = 0; i <= curPos; ++i) {
			if (StonesInfo[i].first == 0) {
				sum += StonesInfo[i].second;
			}
		}
		cout << sum << endl;
	}

	return 0;
}
