#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

int N;
ll A[3000];
const ll INF = 1145141919810893;
ll dp[3000][3000];//dp[i][j]:=[i, j]が残ってる時の、X-Yの値
//本来ならば、太郎が回ってきた時の太郎にとってのベストのX-Y, 次郎が回ってきたときの次郎にとってのベストのX-Y
//を二通り考えるけど、この場合は[i, j]の偶奇により[i, j]の局面で誰が操作するのか決まってるので一つのみ用意する

ll memo(int l, int r) {
	if (dp[l][r] != INF)return dp[l][r];
	
	bool teban;//falseなら太郎　trueなら次郎
	if ((N - (r - l + 1)) % 2 == 0)teban = false;
	else teban = true;

	if (l == r) {
		if (!teban)
			return dp[l][r] = A[l];
		else
			return dp[l][r] = -A[l];
	}

	if (!teban) {
		//X-Yを最大化
		return dp[l][r] = max(memo(l + 1, r) + A[l], memo(l, r - 1) + A[r]);
	}
	else {
		//X-Yを最小化
		return dp[l][r] = min(memo(l + 1, r) - A[l], memo(l, r - 1) - A[r]);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i];
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)dp[i][j] = INF;
	cout << memo(0, N - 1) << endl;

	return 0;
}