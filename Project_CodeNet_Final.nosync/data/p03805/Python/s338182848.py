#順列全探索

from itertools import permutations

N, M = map(int, input().split())
G = [[0]*N for _ in range(N)]
for i in range(M):
  a, b = map(int, input().split())
  G[a-1][b-1] = 1
  G[b-1][a-1] = 1

perms = permutations(range(1, N))
ans = 0

for perm in perms:
  now = 0
  for v in perm:
    if G[now][v] == 0:
      break
    now = v
  else:
    ans += 1
    
print(ans)