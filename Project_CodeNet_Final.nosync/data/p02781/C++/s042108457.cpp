// 생각을 하는 시간이 오래걸리는게 아니라 
// 헷갈려하는 시간이 가장 시간을 좀먹는다.
// 엄청나게 시간이 빨리간다. 차라리 노가다를 해서 명쾌하게 만드는게 가장 빠른 방법이다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>


using namespace std;

char str[200];
int n;

long long dy0[200][10];
long long dy1[200][10];

int d(int a, int b, int c) {
	if (a == 0) return 0;
	if (a == 1) return dy1[b][c];
	if (c > 0) {
		return d(1, b, c) + ((long long)a - 1) * dy0[b][c - 1];
	}
	else {
		return 0;
	}
}

//~ using namespace __gnu_pbds; 
#define mp make_pair
#define endl '\n'
typedef long long ll;

const int INF = 1e9 + 5;
const ll lim = (ll)3e16;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
const ll oo = 1e18 + 5;

//~ typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int check(string s, int k) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
	int n = (int)s.size();
	vector<vector<vector<ll>>> dp(n + 5, vector<vector<ll>>(k + 5, vector<ll>(2)));
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int cnt = 0; cnt < k + 1; ++cnt) {
				int pre_num;
				if (j) pre_num = 9;
				else pre_num = s[i] - '0';
				for (int dig = 0; dig <= pre_num; ++dig) {
					dp[i + 1][cnt + (dig != 0)][j || dig < pre_num] += dp[i][cnt][j];
				}
			}
		}
	}
	//	cout << dp[n][k][0] + dp[n][k][1];
	return dp[n][k][0] + dp[n][k][1];
}





int main(void) {
	int result = scanf("%s %d", str, &n);
	
	dy0[0][0] = 1;
	dy1[0][1] ++;
	for (int i = 1; i <= 150; i++) {
		dy0[i][0] = 1;
		for (int j = 1; j <= 4; j++) {
			dy0[i][j] = dy0[i - 1][j] + 9 * dy0[i - 1][j - 1];
			dy1[i][j] = dy0[i][j];
		}
		dy1[i][1] ++;
	}


//	for (int k = 1; k <= 1000000; k++) {
//		n = 2;
//		sprintf(str, "%d", k);
		int len = strlen(str);

		int dap = 0;
		int n2 = n;
		for (int i = 0; i < len; i++) {
			if (n2 < 0) break;
			dap += d(str[i] - '0', len - i - 1, n2);
			if (str[i] != '0') n2--;
		}


//		int cval = check(str);
		printf("%d\n", dap);
//		printf("%d\n\n", check(string(str), n));
//		if (dap != cval) {
//			printf("error");
//			break;
//		}
//	}
	return 0;
}

