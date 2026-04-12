N, X = map(int, input().split())
a, p = [1], [1]
for i in range(N):
  a.append(a[i]*2+3)
  p.append(p[i]*2+1)

def dfs(N, X):
  if N == 0:
    return 0 if X <= 0 else 1
  elif X <= a[N-1] + 1:
    return dfs(N-1, X-1)
  else:
    return p[N-1] + 1 + dfs(N-1, X-a[N-1]-2)
  
print(dfs(N, X))
