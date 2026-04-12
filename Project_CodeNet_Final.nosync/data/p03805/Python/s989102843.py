def tami(x, vis, cnt):
  global ans
  if cnt == N:
    ans += 1
    #print(vis)
    return
  for i in root[x]:
    if i not in vis:
      tami(i, vis+[i], cnt+1)

N,M = list(map(int,input().split()))
ab = [list(map(int,input().split())) for _ in range(M)]

root = [[] for _ in range(N+2)]
for a,b in ab:
  root[a].append(b)
  root[b].append(a)

visited = []
ans = 0
tami(1, visited+[1], 1)
print(ans)