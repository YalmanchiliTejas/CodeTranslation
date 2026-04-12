import collections 
n,m = map(int,input().split())
g = collections.defaultdict(list)
for i in range(m):
  a,b= map(int,input().split())
  g[a-1].append(b-1)
  g[b-1].append(a-1)
  
#print(g)

ans = 0
def dfs(node,num,visit):
  visite = visit.copy()
  global ans
  num += 1
  if num == n:
    ans += 1
    return
  else:
    visite[node] = True
    for neib in g[node]:
      if visite[neib] == False:
        dfs(neib,num,visite)
  
visited = [False]*n
dfs(0,0,visited)
print(ans)
