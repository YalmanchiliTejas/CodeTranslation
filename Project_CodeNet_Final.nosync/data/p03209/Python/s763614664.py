def f(N, X):
  if N == 0:
    if X >= 1:
      return 1
    return 0
  elif X <= 1 + a[N-1]:
    return f(N-1, X-1)
  else:
    return p[N-1] + 1 + f(N-1, X-a[N-1] - 2)

N, X = map(int, input().split(" "))
a = [1]
p = [1]
for i in range(N):
  a.append(a[i]*2+3)
  p.append(p[i]*2+1)

print(f(N,X))