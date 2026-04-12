N = int(input())
K = int(input())

L = list(map(int, list(str(N))))
M = len(L)
DP = [[[0] * 2 for _ in range(K + 1)] for _ in range(M)]

DP[0][1] = [L[0] - 1, 1]
DP[0][0][0] = 1

for i in range(1, M):
  DP[i][0][0] = DP[i - 1][0][0]
  for j in range(1, K + 1):
    if L[i] != 0:
      DP[i][j][0] = DP[i - 1][j][0]
      DP[i][j][0] += DP[i - 1][j][1]
      DP[i][j][0] += DP[i - 1][j - 1][0] * 9
      DP[i][j][0] += DP[i - 1][j - 1][1] * (L[i] - 1)
      DP[i][j][1] = DP[i - 1][j - 1][1]
    else:
      DP[i][j][0] = DP[i - 1][j][0]
      DP[i][j][0] += DP[i - 1][j - 1][0] * 9
      DP[i][j][1] = DP[i - 1][j][1]

ans = DP[-1][-1][0] + DP[-1][-1][1]
ans = max(0, ans)
print(ans)
