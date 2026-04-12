N, M = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(M)]
X = [[0] * N for _ in range(N)]
for i in range(M):
  X[ab[i][0]-1][ab[i][1]-1] = 1
  X[ab[i][1]-1][ab[i][0]-1] = 1

def dfs(u):
  c = 0
  if len(u) == N:
    return 1
  for i in range(len(X[u[-1]])):
    if X[u[-1]][i] == 1 and i not in u:
      c += dfs(u + [i])
  return c

print(dfs([0]))
