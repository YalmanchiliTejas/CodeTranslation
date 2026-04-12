N = input()
K = int(input())
L = len(N)

S = [ord(N[i]) - ord('0') for i in range(L)]

dp0 = [[0 for _ in range(K+1)] for _ in range(L)]
dp1 = [[0 for _ in range(K+1)] for _ in range(L)]

dp0[0][0] = 1
dp0[0][1] = S[0]-1
dp1[0][0] = 0
dp1[0][1] = 1

for i in range(1, L):
	for j in range(K+1):
		if j == 0:
			dp0[i][j] = dp0[i-1][j]
			dp1[i][j] = dp1[i-1][j]
		else:
			dp0[i][j] = dp0[i-1][j-1]*9 + dp0[i-1][j] 
			if S[i] > 0:
				dp0[i][j] = dp0[i][j] + dp1[i-1][j-1]*(S[i]-1) + dp1[i-1][j]
				
			dp1[i][j] = dp1[i-1][j-(S[i]>0)]
	
print(dp0[L-1][K] + dp1[L-1][K])