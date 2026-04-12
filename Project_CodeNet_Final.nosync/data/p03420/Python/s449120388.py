import sys
input = sys.stdin.readline
N, K = map(int, input().split())
res = 0
for i in range(1, N + 1):
  u = max(i - K, 0)
  v = N // i
  x = max(N % i - K + 1, 0)
  res += u * v + x - (K == 0)
  #print(i, u, v, x)
  #print(res)
print(res)