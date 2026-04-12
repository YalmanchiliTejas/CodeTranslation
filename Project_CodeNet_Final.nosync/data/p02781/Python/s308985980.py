n=input()
k=int(input())
dp=[[[0]*(k+2) for _ in range(2)] for _ in range(len(n)+1)]
dp[0][0][0]=1
for i,c in enumerate(n):
	c=int(c)
	for f in range(2):
		for j in range(k+1):
			for l in range(10*f or c+1):
				dp[i+1][f or l<c][j+(l>0)]+=dp[i][f][j]
print(dp[-1][0][k]+dp[-1][1][k])