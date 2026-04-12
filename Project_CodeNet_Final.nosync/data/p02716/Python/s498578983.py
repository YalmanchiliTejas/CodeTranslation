N = int(input())
A = list(map(int, input().split()))

if N == 2:
  print(max(A[0], A[1]))
  exit()

DP = [[- 10 ** 10] * 3 for _ in range(N)]

DP[0][0] = A[0]
DP[1][0] = A[1]
DP[2][0] = A[0] + A[2]
DP[2][1] = A[2]

for i in range(3, N):
  DP[i][0] = DP[i - 2][0] + A[i]
  DP[i][1] = DP[i - 2][1] + A[i]
  DP[i][2] = DP[i - 2][2] + A[i]
  if i - 3 >= 0:
    DP[i][1] = max(DP[i][1], DP[i - 3][0] + A[i])
    DP[i][2] = max(DP[i][2], DP[i - 3][1] + A[i])
  if i - 4 >= 0:
    DP[i][2] = max(DP[i][2], DP[i - 4][0] + A[i])

ans = 0

if N % 2 == 0:
  ans = max(DP[-1][0], DP[-1][1])
  ans = max(ans, DP[-2][0])
else:
  ans = max(DP[-1][1], DP[-1][2])
  ans = max(ans, DP[-2][0])
  ans = max(ans, DP[-2][1])
  ans = max(ans, DP[-3][0])

print(ans)
