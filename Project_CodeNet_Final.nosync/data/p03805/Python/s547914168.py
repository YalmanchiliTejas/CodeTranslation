n,m=map(int,input().split())
e=[[]for _ in range(n)]
for _ in range(m):
  a,b=map(int,input().split())
  e[a-1]+=[b-1]
  e[b-1]+=[a-1]
def dfs(now,vis):
  vis+=[now]
  if len(vis)==n:return 1
  res=0
  for to in e[now]:
    if to not in vis:
      res+=dfs(to,vis[:])
  return res
print(dfs(0,[]))