N, X, M = map(int, input().split())

ans = 0
A = []
T = [-1]*M
i = 0
f = False
while i<N:
  if T[X]!=-1 and not f:
    f = True
    ans += sum(A[T[X]:])*((N-i)//(i-T[X]))
    i += (N-i)//(i-T[X])*(i-T[X])
    continue
  A += [X]
  T[X] = i
  ans += X
  X = X*X%M
  i += 1
print(ans)
