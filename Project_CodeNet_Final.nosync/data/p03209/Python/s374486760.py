N, X = map(int, input().split())

P = [1]
B = [1]
for i in range(N):
  P.append(P[i] * 2 + 3)
  B.append(B[i] * 2 + 1)

def rec(N, X):
  if N == 0:
    if X <= 0:
      return 0
    else:
      return 1
  elif X <= 1 + P[N - 1]:
    return rec(N - 1, X - 1)
  else:
    return B[N - 1] + 1 + rec(N - 1, X - 2 - P[N - 1])

print(rec(N, X))