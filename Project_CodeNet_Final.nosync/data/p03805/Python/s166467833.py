import sys
sys.setrecursionlimit(10 ** 6)
n,m=map(int,input().split())
g=[[]for i in range(n)]; ans=0
for i in range(m):
  a,b=map(int,input().split())
  a-=1; b-=1
  g[a].append(b)
  g[b].append(a)
# print(g)
def dfs(x,visited):
  global ans
  # print(x,visited)
  for p in g[x]:
    if visited[p]==0:
      visited[p]=1
      if visited.count(1)==n:
        ans+=1
        # print(ans)
      else: 
        dfs(p,visited)
      visited[p]=0
v=[0]*n
v[0]=1
dfs(0,v)
print(ans)