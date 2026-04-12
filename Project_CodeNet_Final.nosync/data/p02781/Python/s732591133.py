N = list(map(int, input()))
K = int(input())

DP_conf = [[0] * (K+1) for _ in range(len(N))]
DP_unco = [[0] * (K+1) for _ in range(len(N))]

DP_conf[0][0] = 1
DP_conf[0][1] = N[0] - 1
DP_unco[0][0] = 0
DP_unco[0][1] = 1

for i in range(1,len(N)):
	for j in range(K+1):
		if j > i+1:
			break
		
		if j == 0:
			DP_conf[i][j] = 1
			DP_unco[i][j] = 0

		else:
			DP_conf[i][j] = DP_conf[i-1][j] + DP_conf[i-1][j-1] * 9
			if N[i] > 0:
				DP_conf[i][j] += DP_unco[i-1][j] + DP_unco[i-1][j-1] * (N[i] - 1)
				DP_unco[i][j] = DP_unco[i-1][j-1]
			else:
				DP_unco[i][j] = DP_unco[i-1][j]

print(DP_conf[-1][K] + DP_unco[-1][K])
			
