def f(n, x):
  if x <= 0:
    return 0
  if x >= 2**(n+2) - 3:
    return 2**(n+1) - 1
  return f(n - 1, x - 1) + f(0, x - 2**(n+1) + 2) + f(n - 1, x - 2**(n+1) + 1)

n, x = map(int, input().split())
print(f(n, x))
