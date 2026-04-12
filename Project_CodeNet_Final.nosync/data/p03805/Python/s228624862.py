n,m = map(int, input().split())
D = [list() for i in range(n)]
for i in range(m):
  a,b = map(int,input().split())
  D[a-1].append(b-1)
  D[b-1].append(a-1)

d = [0]*n
d[0] = 1
cnt = 0

def dfs(x):
  global cnt
  if all(d):
    cnt += 1
    return
  for i in D[x]:
    if d[i] == 0:
      d[i] = 1
      dfs(i)
      d[i] = 0

dfs(0)
print(cnt)