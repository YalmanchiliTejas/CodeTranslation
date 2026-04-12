n, x = map(int, input().split())

num = [2 ** (i + 2) - 3 for i in range(n+1)]
pnum = [2 ** (i+1) - 1 for i in range(n+1)]

def ans(m, y):
  if m == 0:
    return 1
  elif y == 1:
    return 0
  elif y < 2 ** (m + 1) - 1:
    return ans(m - 1, y - 1)
  elif y == 2 ** (m+1) -1:
    return pnum[m-1] + 1
  elif y != num[m]:
    r = y - (2 ** (m+1)-1)
    return pnum[m-1] + 1 + ans(m-1, r)
  else:
    return pnum[m]

print(ans(n, x))
