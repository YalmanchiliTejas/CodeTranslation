import sys
sys.setrecursionlimit(10**9)

def dfs(s,check):
  if len(check)==n:
    if len(set(check))==n:
      return 1
    else:
      return 0
  ans=0
  for i in edge[s]:
    ans+=dfs(i,check+[i])
  return ans

n,m=map(int,input().split())
edge=[[] for _ in range(n+1)]
for i in range(m):
  s,t=map(int,input().split())
  edge[s].append(t)
  edge[t].append(s)
print(dfs(1,[1]))