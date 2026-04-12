#include <bits/stdc++.h>
using namespace std;
#define MAX_N 9

int g[MAX_N][MAX_N];

bool used[MAX_N]; int perm[MAX_N];
// {0,1,2,3,4, ... , n - 1}の並び替えn!通りを生成する
void permutation1(int pos, int n) {
	if (pos == n) {
		return ;
	}
	// permのpos番目を0~n-1のどれにするかのループ
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			perm[pos] = i;
			// iを使ったのでフラグをtrueにしておく
			used[i] = true;
			permutation1(pos + 1, n);
			// 戻ってきたらフラグを戻しておく
			used[i] = false;
		}
	}
	return ;
}

int perm2[MAX_N];
int res = 0;
void permutation2(int n) {
	for (int i = 0; i < n; i++) {
		perm2[i] = i;
	}
	do {
		bool flg = true;
		if (perm2[0] != 0) flg = false;
		for (int i = 0; i < n-1; i++) {
			if (g[perm2[i]][perm2[i+1]] == 0) flg = false;
		}
		if (flg) res++;
	} while (next_permutation(perm2, perm2 + n));
	return ;
}

int main(){
	long long N;
	long long M;
	scanf("%lld",&N);
	scanf("%lld",&M);
	vector<long long> b(M-1+1);
	vector<long long> a(M-1+1);
	for(int i = 0 ; i <= M-1 ; i++){
		scanf("%lld",&a[i]);
		scanf("%lld",&b[i]);
		g[a[i]-1][b[i]-1] = 1;
		g[b[i]-1][a[i]-1] = 1;
	}
	permutation2(N);
	cout << res << endl;
	return 0;
}
