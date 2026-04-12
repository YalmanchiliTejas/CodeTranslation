import itertools
n,m = map(int,input().split())
a = []
c = 0
for _ in [0]*m:
  a += [list(map(int,input().split()))]
for x in list(itertools.permutations(range(2,n+1))):
  y = [1] + list(x)
  f = True
  for i in range(1,n):
    if (not [y[i-1],y[i]] in a) and (not [y[i],y[i-1]] in a):
      f = False
      break
  if f:
    c += 1
print(c)