N,M=map(int,input().split())
tbl=[[0]*(N+1) for _ in range(N+1)]
for i in range(M):
  a,b=map(int,input().split())
  tbl[a][b]=1
  tbl[b][a]=1            # グラフの行列を用いた表現
def dfs(s,visited):
  if len(visited)==N:
    return 1
  
  ans=0
  for i in range(1,N+1):
    if i==s: continue
    if tbl[s][i]==1 and (i not in visited):
      visited.append(i)
      ans+=dfs(i,visited)
      visited.pop()
  return ans 

answer=dfs(1,[1,])
print(answer)
      