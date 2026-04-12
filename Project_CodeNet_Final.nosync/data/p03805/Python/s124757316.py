from itertools import permutations
import math
n,m = map(int,input().split())
G = [[] for i in range(n)]
ans = 0
for i in range(m):
  a,b = map(int,input().split())
  G[a-1].append(b-1)
  G[b-1].append(a-1)
for per in permutations(range(n)):
  if per[0] != 0:
    continue
  for i in range(n-1):
    if not (per[i+1]  in G[per[i]]):
      break
  else:
    ans += 1
print(ans)