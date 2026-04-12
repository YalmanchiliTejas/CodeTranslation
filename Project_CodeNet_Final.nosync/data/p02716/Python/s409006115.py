#設定
import sys
input = sys.stdin.buffer.readline

#ライブラリインポート
from collections import defaultdict

con = 10 ** 9 + 7
#入力受け取り
def getlist():
	return list(map(int, input().split()))

INF = float("inf")

#処理内容
def main():
	N = int(input())
	A = getlist()
	A += [-INF] * 10
	if N % 2 == 0:
		DP0 = [-INF] * (N + 10)
		DP1 = [-INF] * (N + 10)
		DP0[0] = A[0]
		DP1[1] = A[1]
		for i in range(N):
			DP0[i + 2] = max(DP0[i] + A[i + 2] , DP0[i + 2])
			DP1[i + 3] = max(DP0[i] + A[i + 3] , DP1[i + 3])

			DP1[i + 2] = max(DP1[i] + A[i + 2] , DP1[i + 2])

		ans = max(DP0[N - 2], DP1[N - 1])

		print(ans)


	else:
		DP0 = [-INF] * (N + 10)
		DP1 = [-INF] * (N + 10)
		DP2 = [-INF] * (N + 10)
		DP0[0] = A[0]
		DP1[1] = A[1]
		DP2[2] = A[2]
		for i in range(N):
			DP0[i + 2] = max(DP0[i] + A[i + 2] , DP0[i + 2])
			DP1[i + 3] = max(DP0[i] + A[i + 3] , DP1[i + 3])
			DP2[i + 4] = max(DP0[i] + A[i + 4] , DP2[i + 4])

			DP1[i + 2] = max(DP1[i] + A[i + 2] , DP1[i + 2])
			DP2[i + 3] = max(DP1[i] + A[i + 3] , DP2[i + 3])
			
			DP2[i + 2] = max(DP2[i] + A[i + 2] , DP2[i + 2])

		ans = max(DP0[N - 3], DP1[N - 2], DP2[N - 1])

		print(ans)



if __name__ == '__main__':
	main()