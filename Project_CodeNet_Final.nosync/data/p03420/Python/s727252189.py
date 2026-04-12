N, K = map(int, input().split())
if K == 0:
  print(N * N)
else:
  S = 0
  for i in range(K+1, N+1):
    m = N // i
    S += m * (i - K)
    S += max(0, N % i - K + 1)
  print(S)