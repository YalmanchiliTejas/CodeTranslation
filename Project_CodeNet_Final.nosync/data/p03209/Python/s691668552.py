N, X = map(int, input().split())
B = [0] * (N + 1)
P = [1] * (N + 1)
for i in range(N):
  B[i + 1] = 2 * B[i] + 2
  P[i + 1] = 2 * P[i] + 1
S = [B[i] + P[i] for i in range(N + 1)]
cnt = 0
def burg(L, X):
  cnt = 0
  if X <= L:
    return 0
  if L == 0:
    return 1
  if X <= S[L - 1] + 1:
    return burg(L - 1, X - 1)
  if X == S[L]:
    return P[L]
  else:
    return P[L - 1] + 1 + burg(L - 1, X - S[L - 1] - 2)
print(burg(N, X))