#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

#define REP(i,n) for(int i=0;(i)<(n);(i)++)

int main() {
	int N, M;//N<=8なので全探索できる
	int a[40], b[40];
	cin >> N >> M;
	REP(i, M) {
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;//0-indexed
	}

	//N!とおりの順列を生成して，それが可能か調べる
	//next permutation
	int perm[10];
	REP(i, N) {
		perm[i] = i;
	}

	bool flag;
	int ans = 0;
	do {
		if (perm[0] != 0) continue;

		for (int i = 0;i < N - 1;i++) {

			flag = 0;
			for (int j = 0;j < M;j++) {
				if (((perm[i] == a[j]) && (perm[i + 1] == b[j])) || ((perm[i] == b[j]) && (perm[i + 1] == a[j]))) {//方向なしの結合なのでこれではだめ
					flag = 1;
					break;
				}
			}

			if (flag == 0) break;//そのパスがなかったらbreak

			if (i == N - 2) ans++;//最後まで回ったらans++
		}

		//REP(i, N) {
		//	cout << perm[i] << endl;
		//}

	} while (next_permutation(perm, perm + N));

	cout << ans << endl;
	return 0;
}