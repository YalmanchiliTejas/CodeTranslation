import itertools 

n, m = map(int, input().split())
G = [[] for _ in range(n)]
for i in range(m):
  a, b = map(int, input().split())
  a, b = a-1, b-1
  G[a].append(b)
  G[b].append(a)
  
P = itertools.permutations(range(1, n), n-1)

ans = 0
for p in P:

  for i in range(n-1):

    if i==0:
      pnow = 0
      pnext = p[0]
    else:
      
      pnow = p[i-1]
      pnext = p[i]
    if pnext not in G[pnow]:
      break
  else:
    ans += 1
    continue
  
  
print(ans)