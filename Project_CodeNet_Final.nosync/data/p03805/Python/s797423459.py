N, M = map(int, input().split())
g = [[] for i in range(N)]

for i in range(M):
  a, b = map(int, input().split())
  g[a-1].append(b-1)
  g[b-1].append(a-1)

memo = {}
All_used = (1 << N) - 1


def dfs(v, used):
  if used == All_used:
    return 1
  key = (v, used)
  if key in memo:
    return memo[key]
  ans = 0
  for i in g[v]:
    if used & (1 << i):
      continue
    used ^= (1 << i)
    ans += dfs(i, used)
    used ^= (1 << i)
  memo[key] = ans
  return ans

print(dfs(0, 1))
