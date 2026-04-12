#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, D[1 << 19], S[1 << 19];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) scanf("%d", &D[i]);

	bool flag = true;

	// ステップ 1 : 左から行けるか
	for (int i = 1; i <= N; i++) {
		int sz = D[i] / 10;
		int cl = i, cr = i + sz; cl = max(cl, 1); cr = min(cr, N);
		S[cl + 1]++; S[cr + 1]--;
	}
	for (int i = 1; i <= N + 1; i++) S[i] += S[i - 1];
	for (int i = 2; i <= N; i++) { if (S[i] == 0) flag = false; }
	for (int i = 0; i <= N + 1; i++) S[i] = 0;

	// ステップ 2 : 右から行けるか
	for (int i = 1; i <= N; i++) {
		int sz = D[i] / 10;
		int cl = i - sz, cr = i; cl = max(cl, 1); cr = min(cr, N);
		S[cl + 1]++; S[cr + 1]--;
	}
	for (int i = 1; i <= N + 1; i++) S[i] += S[i - 1];
	for (int i = 2; i <= N; i++) { if (S[i] == 0) flag = false; }
	for (int i = 0; i <= N + 1; i++) S[i] = 0;

	if (flag == true) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}
