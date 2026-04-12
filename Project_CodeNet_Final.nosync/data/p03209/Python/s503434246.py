N, X = map(int, input().split())
a, p = [1], [1]

for i in range(1, N+1):
  a.append(2 * a[i-1] + 3)
  p.append(2 * p[i-1] + 1)
  
def f(N, X):
  if N == 0:
    return 0 if X <= 0 else 1
  elif X <= 1 + a[N-1]:
    return f(N-1, X-1)
  else:
    return f(N-1, X-a[N-1]-2) + p[N-1] + 1
  
print(f(N, X))