#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include<queue>
using namespace std;
int edge[10][10] = {};

int main() {
	int N, M, ans = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		edge[a][b] = 1;
		edge[b][a] = 1;
	}
	vector<int> v;
	for (int i = 2; i <= N; i++) {
		v.push_back(i);
	}

	do {
		int now_v = 1;
		bool flag = true;
		for (int i = 0; i < v.size(); i++) {
			if (edge[now_v][v[i]] == 1) {
				now_v = v[i];
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) ans++;
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
	return 0;
}
