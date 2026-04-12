#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;

int main(void) {
	int N;
	while (cin >> N, N) {
		vector<int> score(N);
		for (int i = 0; i < N; i++)
			cin >> score[i];
		sort(score.begin(), score.end());
		
		int sum = 0;
		for (vector<int>::iterator it = score.begin() + 1; it != score.end() - 1; it++)
			sum += *it;
		int avg = sum / (N - 2);

		cout << avg << endl;
	}

	return 0;
}