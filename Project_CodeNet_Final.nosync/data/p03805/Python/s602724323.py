n,m = map(int, input().split())
arr = [[0]*n for _ in range(n)]
for _ in range(m):
  a,b = map(int, input().split())
  arr[a-1][b-1] = 1
  arr[b-1][a-1] = 1
d = [0]*n
d[0] = 1
cnt = 0
def dfs(x):
  global cnt
  if all(d):
    cnt += 1
  for i in range(1,n+1):
    if arr[x-1][i-1] and d[i-1] == 0:
      d[i-1] = 1
      dfs(i)
      d[i-1] = 0
dfs(1)
print(cnt)