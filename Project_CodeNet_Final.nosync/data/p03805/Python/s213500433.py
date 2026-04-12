import itertools
N, M = map(int, input().split())
edge = [[False]*N for _ in range(N)]
ans = 0
for _ in range(M):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  edge[a][b] = True
  edge[b][a] = True
for i in itertools.permutations(range(N), N):
  if i[0] == 0:
    for j in range(N):
      if j == N-1:
        ans += 1
        break
      if not edge[i[j]][i[j+1]]:
        break
print(ans)