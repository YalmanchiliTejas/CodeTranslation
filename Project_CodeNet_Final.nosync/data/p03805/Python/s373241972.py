import sys
sys.setrecursionlimit(1000000)

n, m = map(int, input().split())
adlist = [[] for _ in range(n)]
for _ in range(m):
  a, b = map(lambda x:int(x)-1, input().split())
  adlist[a] += [b]
  adlist[b] += [a]

ans = 0
used = [0] * n 
used[0] = 1
def dfs(u):
  global ans
  if sum(used) == n:
    ans += 1
    return 
  for v in adlist[u]:
    if used[v] == 0:
      used[v] = 1
      dfs(v)
      used[v] = 0

  return 

dfs(0)
print(ans)
