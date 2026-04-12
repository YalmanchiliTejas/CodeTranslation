#設定
import sys
input = sys.stdin.buffer.readline

#ライブラリインポート
from collections import defaultdict

#入力受け取り
def getlist():
	return list(map(int, input().split()))

#処理内容
def main():
	N, K = getlist()
	ans = 0
	for i in range(K + 1, N + 1):
		ans += (N // i) * (i - K)
		if N % i >= K and N % i != 0:
			ans += N % i - K + 1

	if K == 0:
		print(N ** 2)
	else:
		print(ans)


if __name__ == '__main__':
	main()