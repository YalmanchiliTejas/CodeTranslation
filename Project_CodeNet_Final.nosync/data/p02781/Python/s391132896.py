N = input()
K = int(input())
L = len(N)

# dp1 = the higest digit is 0, dp2 = the highest digit is not 0
dp1 = [[0] * (K+1) for _ in range(L+1)]
dp2 = [[0] * (K+1) for _ in range(L+1)]
for i in range(L+1):
    dp1[i][0] = 1
    for j in range(1, K+1):
        dp1[i][j] = dp1[i-1][j] + dp2[i-1][j]
        dp2[i][j] = 9 * (dp1[i-1][j-1] + dp2[i-1][j-1])
ans = dp1[L][K] + dp2[L][K]
d = K
for i in range(L):
    if N[i] != '0':
        ans -= dp2[L-i][d] * (9-int(N[i])) // 9
        d -= 1
    else:
        ans -= dp2[L-i][d]
    if d == 0:
        break
print(ans)
