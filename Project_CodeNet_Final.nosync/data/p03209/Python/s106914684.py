N, X = map(int, input().split())
b = [1]
p = [1] 
for i in range(N + 1):
  b.append(b[i] * 2 + 3)
  p.append(p[i] * 2 + 1)
def solve(n, x):
  if n <= 0:
    return 0 if x <= 0 else 1
  elif x <= 1 + b[n - 1]:
    return solve(n - 1, x - 1)
  else:
    return p[n - 1] + 1 + solve(n - 1, x - 2 - b[n - 1])
print(solve(N, X))