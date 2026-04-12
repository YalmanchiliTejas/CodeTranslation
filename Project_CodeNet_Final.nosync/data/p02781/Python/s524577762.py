N = int(input())
K = int(input())

"""
dp[i][j][k]
i: 決定した桁数
j: N以下確定
k: 0出ない数字がちょうどk個(k = 0,1,2,3)
   4個以上(k=4)
"""

def solve(a):
	a = str(a)
	L = len(a)
	dp = [[[0]*5 for i in range(2)] for j in range(L+1)]
	dp[0][0][0] = 1
	for i in range(L):
		D = int(a[i])
		for j in range(2):
			for k in range(5):
				for d in range(10 if j else D+1):
					if k>=4:
						dp[i+1][j or (d<D)][k] += dp[i][j][k]
					else:
						if d!=0:
							dp[i+1][j or (d<D)][k+1] += dp[i][j][k]
						else:
							dp[i+1][j or (d<D)][k] += dp[i][j][k]
	return dp[L][0][K] + dp[L][1][K]

print(solve(N))