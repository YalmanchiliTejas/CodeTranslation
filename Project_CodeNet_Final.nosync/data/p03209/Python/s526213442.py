N, X = map(int, input().split())

def calc(n, x):
  if x == 0: return 0
  if n == 0: return 1
  if x < 2**(n+1) - 1:
    return calc(n-1, x-1)
  else:
    return 2**n + calc(n-1, x-2**(n+1)+1)

print(calc(N, X))