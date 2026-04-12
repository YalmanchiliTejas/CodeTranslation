#include <iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<math.h>
#include<bitset>
#include<string>
#include<queue>

using namespace std;
int G[9][9];


int main() {
	int N, M;
	int ans = 0;
	cin >> N >> M;
	int A[50], B[50];

	

	for (int i = 0; i < M; i ++) {
		cin >> A[i] >> B[i];
		G[A[i]][B[i]] = 1;
		G[B[i]][A[i]] = 1;
	}

	vector<int> v(N);
	
	for (int i = 0; i < N; i++) {
		v[i] = i + 1;
	}

	do {
		if (v[0] == 1) {
			int flag = 1;
			for (int i = 0; i < N - 1; i++) {
				if (G[v[i]][v[i + 1]] == 0)flag = 0;
			}
			if (flag == 1)ans++;
		}


		
	} while (next_permutation(v.begin(), v.end()));


	cout << ans << endl;

	return 0;
}