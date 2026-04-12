def dfs(i):
  global count
  global seen
  global G

  end = True
  for n in range(N):
    if seen[n] == 0 and n != i:
      end = False

  if (end):
    count += 1
    return

  seen[i] = 1
  for g in G:
    if g[0] == i:
      if seen[g[1]] == 1:
        continue
      dfs(g[1])
  
    if g[1] == i:
      if seen[g[0]] == 1:
        continue
      dfs(g[0])

  seen[i] = 0

N, M = map(int, input().split())
li = [list(map(int, input().split())) for n in range(M)]

G = []

for i in li:
  G.append([i[0]-1, i[1]-1])

count = 0
seen = [0] * N
dfs(0)

print(count)