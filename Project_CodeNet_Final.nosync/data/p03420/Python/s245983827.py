import sys
input = sys.stdin.readline
N, K = map(int, input().split())
if K == 0:
  print(N ** 2)
  exit(0)
res = 0
for i in range(1, N + 1):
  if i <= K: continue
  res += i - K
  for j in range(i, N + 1, i):
    res += min(N + 1, j + i) - min(N + 1, j + K)
print(res)