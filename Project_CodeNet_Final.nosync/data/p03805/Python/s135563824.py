from collections import defaultdict
from collections import deque

N, M = map(int, input().split())

D = defaultdict(list)
for i in range(M):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  D[a].append(b)
  D[b].append(a)

q = deque([])
q.append(0)

ans = 0
def dfs(n, q):
  global ans
  q.append(n)
  if len(q) == N:
    ans += 1
  else:
    for b in D[n]:
      if b not in q:
        dfs(b, q)
        q.pop()

dfs(0, [])
print (ans)