#include <cstdio>
#include <iostream>
#include <string>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

const long long INF = 1000000007;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int , pii> piii;
typedef pair<pii, pii> piiii;

int d;
int arr[10011];
int dp[10011][101];

int main() {	
	string s;
	getline(cin, s);
	int len = s.length();
	for (int i = len; i >0; i--) arr[i] = s[len-i] - '0';
	scanf("%d", &d);
	int tmp = 0;
	for (int i = 2; i <= len; i++) tmp += arr[i];
	if (d == 1) {
		ll x[10011];
		x[1] = 1;
		for (int i = 2; i <= 10001; i++) x[i] = (x[i - 1] * 10) % INF;
		ll ans = 0;
		for (int i = 1; i <= len; i++) {
			ans = (ans + x[i] * arr[i]) % INF;
		}
		printf("%lld\n", ans);
		return 0;
	}
	for (int i = 1; i <= 10001; i++) {
		for (int j = 0; j < 100; j++) dp[i][j] = 0;
	}
	for (int i = 0; i <= 9; i++) {
		dp[1][i%d]++;
	}
	for (int i = 2; i <= 10001; i++) {
		for (int j = 0; j <= 9; j++) {
			//i번째자리가 j인 경우
			for (int k = 0; k < d; k++) dp[i][(j + k) % d] = (dp[i][(j+k)%d]+dp[i - 1][k])%INF;
		}
	}
	/*for (int i = 1; i <= 2; i++) {
		for (int j = 0; j < d; j++) printf("%d ", dp[i][j]);
		printf("\n");
	}*/
	int ans = 0;
	int cur = len;
	int sum = 0;
	while (cur!=1) {
		if (arr[cur] == 0) {
			cur--;
			continue;
		}
		ans = (ans + dp[cur - 1][sum]) % INF;
		sum = (sum + d - 1) % d;
		arr[cur] --;
	}
	int cnt = 0;
	for (int i = 0; i <= arr[1]; i++) {
		if ((tmp + i) % d == 0) cnt++;
	}
	printf("%d\n", (ans + cnt -1+INF)%INF);
}
