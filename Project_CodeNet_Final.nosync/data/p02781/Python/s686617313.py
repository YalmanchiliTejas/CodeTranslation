
#ライブラリインポート
from collections import defaultdict

con = 10 ** 9 + 7
#入力受け取り
def getlist():
	return list(map(int, input().split()))

#処理内容
def main():
	N = list(list(map(int, list(input()))))
	K = int(input())
	
	#桁DP
	M = len(N)
	DP = [[[0] * 4 for i in range(M)] for j in range(2)]
	#最初の処理
	DP[0][0][1] = 1
	DP[1][0][1] = N[0] - 1
	for i in range(1, M):
		if N[i] == 0:
			DP[0][i][1] += DP[0][i - 1][1]
			DP[0][i][2] += DP[0][i - 1][2]
			DP[0][i][3] += DP[0][i - 1][3]

			DP[1][i][1] += DP[1][i - 1][1]
			DP[1][i][2] += DP[1][i - 1][1] * 9 + DP[1][i - 1][2]
			DP[1][i][3] += DP[1][i - 1][2] * 9 + DP[1][i - 1][3]
		else:
			DP[0][i][2] += DP[0][i - 1][1]
			DP[0][i][3] += DP[0][i - 1][2]

			DP[1][i][2] += DP[0][i - 1][1] * (N[i] - 1)
			DP[1][i][3] += DP[0][i - 1][2] * (N[i] - 1)
			DP[1][i][1] += DP[0][i - 1][1]
			DP[1][i][2] += DP[0][i - 1][2]
			DP[1][i][3] += DP[0][i - 1][3]

			DP[1][i][1] += DP[1][i - 1][1]
			DP[1][i][2] += DP[1][i - 1][1] * 9 + DP[1][i - 1][2]
			DP[1][i][3] += DP[1][i - 1][2] * 9 + DP[1][i - 1][3]
		DP[1][i][1] += 9

	ans = DP[0][M - 1][K] + DP[1][M - 1][K]
	# print(DP)
	print(ans)

if __name__ == '__main__':
	main()