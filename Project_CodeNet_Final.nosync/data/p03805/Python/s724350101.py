N, M = map(int, input().split())
root = {i: [] for i in range(N)}
for i in range(M):
  a, b = map(int, input().split())
  root[a-1].append(b-1)
  root[b-1].append(a-1)
fact = 1
for i in range(N-1):
  fact *= (i+1)
realcnt = 0
for i in range(fact):
  p = [i for i in range(1, N)]
  L = []
  for j in range(N-1):
    L.append(i % (j + 1))
    i //= (j + 1)
  LL = [0]
  for j in range(N-1):
    LL.append(p[L[N-2-j]])
    p.remove(p[L[N-2-j]])
  cnt = 1
  for j in range(N-1):
    if LL[j+1] in root[LL[j]]:
      cnt += 1
  if cnt == N:
    realcnt += 1
print(realcnt)