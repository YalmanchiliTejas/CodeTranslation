#include<iostream>
#include<cstdint>
using namespace std;

const int MAX = 50;
const int64_t INF = 4611686018427387903; // 10^62-1、使わない辺とかに用いる

bool check(int64_t x, int64_t *a, int N) {
	for (int i = 0;i < N;i ++) {
		int64_t operate = 0;
		for (int j = 0;j < N;j ++) {
			operate += (a[j] + x - i + 1) / (N + 1);
		}
		if (operate <= x - i) return false;
	}
	return true;
}

int64_t binarySearch(int64_t l, int64_t r, int64_t *a, int N) {
	int64_t mid;
	for (mid = r >> 1;r - l > 1;mid = l + (r - l >> 1)) {
		if (check(mid, a, N)) l = mid;
		else r = mid;
	}
	return mid;
}
int main() {
	int N;
	int64_t a[MAX];
	cin >> N;
	for (int i = 0;i < N;i ++) cin >> a[i];
	
	int64_t ans = binarySearch(0, INF, a, N);
	if (check(ans, a, N)) ans ++;
	cout << ans;
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

操作回数をX回と決め打ちます
この時、ある数aに対して行わなければならない操作回数は(a+X-N+1)/(N+1)の端数切り上げです
ということは、O(N^2)でX回以内にできるか分かります
よって後はXを二分探索すれば良いです、O(N^2log(max(a)))
*/