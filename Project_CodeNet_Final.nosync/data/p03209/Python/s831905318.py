def burg(lev,x):
  if lev <= 0:
    return int(x>0)
  if x <= 1:
    return 0
  if 1 < x < h[lev-1]+2:
    return burg(lev-1,x-1)
  if x == h[lev-1]+2:
    return p[lev-1] + 1
  if h[lev-1]+2 < x < h[lev]:
    return p[lev-1] + 1 + burg(lev-1,x-(h[lev-1]+2))
  if x >= h[lev]:
    return p[lev]

n,x = map(int, input().split())
h = [1]*(n+2)
p = [1]*(n+2)
for i in range(1,n+2):
  h[i] = h[i-1]*2 + 3
  p[i] = p[i-1]*2 + 1
print(burg(n,x))