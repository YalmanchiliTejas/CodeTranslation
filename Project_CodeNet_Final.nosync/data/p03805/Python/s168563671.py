n,m=map(int,input().split())
g=[[]for _ in range(n)]
for _ in range(m):
  a,b=map(int,input().split())
  g[a-1].append(b-1)
  g[b-1].append(a-1)
import sys
sys.setrecursionlimit(10**7)

def dfs(t,seen):
  if all(seen):
    return 1
  ret=0
  l=g[t]
  for li in l:
    if seen[li]==0:
      seenli=seen.copy()
      seenli[li]=1
      ret+=dfs(li,seenli)
  return ret
seen=[0]*n
seen[0]=1
print(dfs(0,seen))