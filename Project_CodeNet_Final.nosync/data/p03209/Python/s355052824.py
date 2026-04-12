def f(N, X):
  m = 2 ** (N + 1) - 1
  if X <= N:
    return 0
  elif N == 0:
    return 1
  elif X < m:
    return f(N-1, X-1)
  else:
    return 2 ** N + f(N-1, X-m)

N, X = map(int, input().split())
print(f(N, X))