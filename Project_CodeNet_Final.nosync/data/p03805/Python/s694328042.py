import numpy as np

N, M = map(int, input().split())
adj = np.zeros((N+1, N+1))
for m in range(M):
  a, b = map(int, input().split())
  adj[a, b] = 1
  adj[b, a] = 1

from itertools import permutations

nodes = [n for n in range(2, N+1)]
ans = 0

for case in permutations(nodes):
  success = True
  for i, nd in enumerate(case):
    if i == 0:
      f = 1
    else:
      f = case[i-1]

    t = case[i]

    if adj[f, t] != 1:
      success = False
      break

  if success:
    ans += 1

print(ans)