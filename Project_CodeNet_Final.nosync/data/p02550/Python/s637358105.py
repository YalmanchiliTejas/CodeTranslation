

N, X, M = map(int, input().split())

R = [-1] * M
R[X % M] = 0
A = [0] + [X % M]
a = X
for i in range(1, N):
  a **= 2
  a %= M
  if R[a] == -1:
    R[a] = i
    A += [A[-1] + a]
  else:
    print(X - X % M + (A[-1] - A[R[a]]) * ((N - R[a]) // (i - R[a])) + A[R[a] + (N - R[a]) % (i - R[a])])
    exit()
print(A[-1] + X - X % M)