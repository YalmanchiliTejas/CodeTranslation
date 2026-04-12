N, M = map(int,input().split(" "))
nm = [[0 for i in range(N)] for j in range(N)]
for i in range(M):
  x,y = (map(int,input().split(" ")))
  nm[x-1][y-1]=1
  nm[y-1][x-1]=1

cnt = [0]
def dfs(V, s):
  V[s]=1
  if sum(V)==N:
    cnt[0] += 1
  for i in range(N):
    if nm[i][s]==1 and V[i]==0:
      dfs(V,i)
  V[s]=0
  
dfs([0]*N,0)
print(cnt[0])