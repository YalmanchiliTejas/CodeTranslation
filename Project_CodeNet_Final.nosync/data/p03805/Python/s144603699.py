n,m = map(int, input().split())
arr = [list() for _ in range(n)]
for _ in range(m):
  a,b = map(int, input().split())
  arr[a-1].append(b)
  arr[b-1].append(a)
d = [0]*n
d[0] = 1
cnt = 0
def dfs(x):
  global cnt
  if all(d):
    cnt += 1
    return
  for i in arr[x-1]:
    if d[i-1] == 0:
      d[i-1] = 1
      dfs(i)
      d[i-1] = 0
dfs(1)
print(cnt)