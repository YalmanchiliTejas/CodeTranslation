h, w = map(int, input().split())
s = []
sh = 0
for i in range(h):
  t = input()
  sh += t.count('#')
  s.append(t)

visited = [[False for j in range(w)] for i in range(h)]

dx = [0,1]
dy = [1,0]
def dfs(x,y,cnt):
  visited[x][y] = True
  cnt += 1
  if x == h-1 and y == w-1:
    if cnt == sh:
      print ('Possible')
      exit()
    return
  for i in range(2):
    a = x+dx[i]
    b = y+dy[i]
    if a < 0 or b < 0 or a >= h or b >= w or visited[a][b] or s[a][b] == '.':
      continue
    dfs(a,b,cnt)

dfs(0,0,0)

print ('Impossible')