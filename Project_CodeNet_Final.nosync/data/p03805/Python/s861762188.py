from collections import deque

N, M = list(map(int, input().split()))
G = [[] for _ in range(N)]
for _ in range(M):
  a, b = list(map(int, input().split()))
  G[a-1].append(b-1)
  G[b-1].append(a-1)
  
ans = 0
v = 0
s = 1
l = 1
q = deque()
q.append((v, s, l))

while q:
  v, s, l = q.popleft()
  if l == N:
    ans += 1
    continue
  for nv in G[v]:
    if s&(1<<nv) == 0:
      q.append((nv, s|(1<<nv), l+1))
print(ans)