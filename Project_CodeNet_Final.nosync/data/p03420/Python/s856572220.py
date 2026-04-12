import sys
input = sys.stdin.readline
N, K = map(int, input().split())
res = 0
for x in range(K + 1, N + 1):
  res += (N // x) * (x - K) + max(0, N % x - K + (K > 0))
  #print(x, res)
print(res)