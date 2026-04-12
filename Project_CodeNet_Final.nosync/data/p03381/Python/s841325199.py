N = int(input())
X = list(map(int, input().split()))

X_sorted = sorted(X)
m = X_sorted[N // 2]

for i in range(N):
  if X[i] < m:
    res = X_sorted[N // 2]
  elif X[i] >= m:
    res = X_sorted[N // 2 - 1]

  print(res)
      