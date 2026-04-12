n,m=map(int,input().split())
ab=[set(map(int,input().split())) for _ in range(m)]
def dfs(v,visited):
  if v in visited:
    return 0
  if len(visited|{v})==n:
    return 1
  return sum(dfs(i,visited|{v}) for i in range(1,n+1) if {i,v} in ab)
print(dfs(1,set()))