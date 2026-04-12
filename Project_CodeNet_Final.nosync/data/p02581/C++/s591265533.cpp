#include <bits/stdc++.h>

using namespace std;

const int N = 3 * 2005;
const int C = 2005;

int n, a[N];

int mx_ind[N];
int mx_color[C];
int mx_ic[N][C];

// get max val(index, anything)
// get max val(index, color)
// get max val(color, color)
// lazy increment

int lz;

int get_ind(int i) {
	return mx_ind[i] + lz;
}

int get_ind_col(int i, int c) {
	return mx_ic[i][c] + lz;
}

int get_col_col(int c) {
	return mx_color[c] + lz;
}

void add(int i, int j, int val) {
	val -= lz;
	mx_ind[i] = max(mx_ind[i], val);
	mx_ind[j] = max(mx_ind[j], val);
	if(a[i] == a[j]) {
		mx_color[ a[i] ] = max(mx_color[ a[i] ], val);
	}
	mx_ic[i][ a[j] ] = max(mx_ic[i][ a[j] ], val);
	mx_ic[j][ a[i] ] = max(mx_ic[j][ a[i] ], val);
}
void lazy_inc() {
	lz++;
}

int dp[N][3];
int dp2[3][3];

int main() {
	memset(mx_ind, -7, sizeof mx_ind);
	memset(mx_color, -7, sizeof mx_color);
	memset(mx_ic, -7, sizeof mx_ic);
	scanf("%d", &n);

	n *= 3;

	for(int i = 0; i < n; i++) scanf("%d", a + i);

	add(0, 1, 0);

	for(int i = 2; i + 2 < n; i += 3) {
		for(int pos = 0; pos < 3; pos++) {
			int b = 0, c = 0;
			while(b == pos) b++;
			while(c == pos or c == b) c++;
			b += i, c += i;
			for(int j = 0; j < i; j++) {
				int &ans = dp[j][pos];
				ans = 0;
				if(a[b] == a[c]) {
					ans = max(ans, get_ind_col(j, a[b]) + 1);
				}
				ans = max(ans, get_ind(j));
			}
		}
		int tmp = 0;
		for(int j = 0; j < i; j++) {
			tmp = max(tmp, get_ind(j));
		}
		for(int p1 = 0; p1 < 3; p1++) for(int p2 = p1 + 1; p2 < 3; p2++) {
			int p3 = 0;
			while(p3 == p1 or p3 == p2) p3++;
			int &ans = dp2[p1][p2];
			ans = 0;
			ans = max(ans, get_col_col(a[i + p3]) + 1);
			ans = max(ans, tmp);
		}

		if(a[i] == a[i + 1] and a[i + 1] == a[i + 2]) lazy_inc();

		for(int pos = 0; pos < 3; pos++) {
			for(int j = 0; j < i; j++) {
				add(j, i + pos, dp[j][pos]);
			}
		}
		for(int p1 = 0; p1 < 3; p1++) for(int p2 = p1 + 1; p2 < 3; p2++) {
			add(i + p1, i + p2, dp2[p1][p2]);
		}
	}

	int ans = 0;

	ans = max(ans, get_col_col(a[n - 1]) + 1);
	for(int i = 0; i < n - 1; i++) {
		ans = max(ans, get_ind(i));
	}

	printf("%d\n", ans);
}
