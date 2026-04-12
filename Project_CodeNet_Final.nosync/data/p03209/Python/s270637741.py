N, X = map(int, input().split())

a, p = [1 for i in range(N+1)], [1 for i in range(N+1)]
for i in range(1,N+1):
  a[i] = a[i-1] * 2 + 3
  p[i] = p[i-1] * 2 + 1

"""
B a[i-1] P a[i-1] B

"""
def solve(level, under):
  #print(level,under)
  if level == 0:
    return 1 if under > 0 else 0
  elif under == 0:
    return 0
  elif under <= a[level-1] + 1:
    return solve(level-1, under-1)
  elif under == a[level-1] + 2:
    return p[level-1] + 1
  elif under == a[level]:
    return p[level]
  else:
    return p[level-1]+1 + solve(level-1, under - (a[level-1]+2))
  
print(solve(N,X))