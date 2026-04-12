def makelist(n, m):
  return [[False for i in range(m)] for j in range(n)]


N, M = map(int, input().split())
graph = [0]*N
ans = [0]

for i in range(N):
  graph[i] = []
  
for i in range(M):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  graph[a].append(b)
  graph[b].append(a)
  
def dfs(now, dp):
  if dp.count(True) == N:
    ans[0] += 1
  else:
    for e in graph[now]:
      if not dp[e]:
        nextdp = dp[:]
        nextdp[e] = True
        dfs(e, nextdp)

first = [False]*N
first[0] = True
dfs(0, first)
print(ans[0])