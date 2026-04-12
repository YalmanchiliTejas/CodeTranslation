from collections import defaultdict as dd
from collections import deque as dq
N, M = map(int, input().split())
e = dd(list)
for _ in range(M):
  u, v = map(int, input().split())
  e[u].append(v)
  e[v].append(u)
dp = [[0] * (N + 1) for _ in range(2 ** N)]
dp[1][1] = 1
Q = dq([])
Q.append((1, 1))
visited = set()
visited.add((1, 1))
while len(Q):
  i, j = Q.popleft()
  for p in e[j]:
    temp = i ^ (1 << (p - 1))
    if temp > i:
      #print(i, p, temp)
      dp[temp][p] += dp[i][j]
      if not (temp, p) in visited:
        Q.append((temp, p))
        visited.add((temp, p))
print(sum(dp[2 ** N - 1]))