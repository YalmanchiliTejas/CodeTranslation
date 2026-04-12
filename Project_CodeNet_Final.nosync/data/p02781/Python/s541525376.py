N = list(map(int,list(input())))
K = int(input())
L = len(N)
dp1 = [[0 for i in range(K+1)] for j in range(L+1)]
dp2 = [[0 for i in range(K+1)] for j in range(L+1)]
dp1[0][0] = 1

for i in range(L):
    for j in range(K+1):
        if N[i] == 0:
            dp1[i+1][j] += dp1[i][j]
        else:
            dp2[i+1][j] += dp1[i][j]
            if j > 0:
                dp1[i+1][j] += dp1[i][j-1]
                dp2[i+1][j] += dp1[i][j-1] * (N[i] - 1)
        if j > 0:
            dp2[i+1][j] += dp2[i][j-1] * 9
        dp2[i+1][j] += dp2[i][j]

ans = dp1[L][K] + dp2[L][K]

print(ans)