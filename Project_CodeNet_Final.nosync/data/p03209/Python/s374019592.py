N, X = map(int, input().split())

def f(n, x):
  if x == 1:
    return 1 if n == 0 else 0
  elif x <= 2**(n + 1) - 2:
    return f(n - 1, x - 1)
  elif x == 2**(n + 1) - 1:
    return 2**n
  elif x <= 2**(n + 2) - 4:
    return f(n -1, x - 2**(n + 1) + 1) + 2**n
  else:
     return 2**(n + 1) - 1

ans = f(N, X)
print(ans)