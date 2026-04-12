n = list(str(input()))
l = len(n)
for i in range(l):
	n[i] = int(n[i])
k = int(input())
dp0 = [[0 for _ in range(4)] for _ in range(l+1)]
dp1 = [[0 for _ in range(4)] for _ in range(l+1)]
dp0[1] = [1, n[0]-1, 0, 0]
dp1[1] = [0, 1, 0, 0]
for i in range(2,l+1):
	for j in range(4):
		p = n[i-1]
		if j == 0:
			if p == 0:
				dp0[i][j] = dp0[i-1][j]
				dp1[i][j] = dp1[i-1][j]
			else:
				dp0[i][j] = 1
				dp1[i][j] = 0
		elif p == 0:
			dp1[i][j] = dp1[i-1][j]
			dp0[i][j] = dp0[i-1][j] + 9 * dp0[i-1][j-1]
		else:
			dp1[i][j] = dp1[i-1][j-1]
			dp0[i][j] = dp0[i-1][j] + 9 * dp0[i-1][j-1] + dp1[i-1][j] + (p-1) * dp1[i-1][j-1]
print(dp0[l][k] + dp1[l][k])