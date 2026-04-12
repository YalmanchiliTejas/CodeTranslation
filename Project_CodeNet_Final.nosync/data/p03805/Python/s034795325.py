from itertools import permutations as per
n,m = map(int,input().split())
g = [[] for i in range(n)]
for i in range(m):
  a,b = map(int,input().split())
  a-=1;b-=1
  g[a].append(b)
  g[b].append(a)
c = 0
for i in per(range(2,n+1)):
  cur = 1
  f = 1
  for j in range(n-1):
    pre,cur = cur,i[j]
    if cur-1 not in g[pre-1]:
      f = 0
      break
  c += f
print(c)