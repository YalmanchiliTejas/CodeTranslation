N, M = map(int, input().split())
E = [[] for i in range(N)]
for i in range(M):
  a, b = map(int, input().split())
  a, b = a-1, b-1
  E[a].append(b)
  E[b].append(a)
r = 0
c = 0
s = 1
l = 1
q = [(c, s, l)]
while q:
  c, s, l = q.pop()
  if l == N:
    r += 1
    continue
  for n in E[c]:
    if s&(1<<n) == 0:
      q.append((n, s|(1<<n), l+1))
print(r)
