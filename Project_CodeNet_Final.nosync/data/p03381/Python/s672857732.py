N = int(input())
X = list(map(int, input().split()))
L = [0 for _ in range(N)]
for i in range(N):
  X[i] = X[i] * N + i
X.sort()
d = N // 2
for i in range(N):
  if i < d:
    L[X[i]%N] = X[d] // N
  else:
    L[X[i]%N] = X[d-1] // N
for i in range(N):
  print(L[i])