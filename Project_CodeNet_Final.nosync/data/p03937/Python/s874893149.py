h,w = map(int,input().split())
g = [['.'] * (w+2) for i in range(h+2)]
ss = set() #'#'のset
for i in range(h):
  g[i+1][1:-1] = list(input())
  for j in range(w):
    if g[i+1][j+1] == '#':
      ss.add((i+1,j+1))
if g[1][1] == '.':
  print('Impossible')
  exit()
cur = (1,1)
ts = set() #通った点のset
ts.add(cur)
while cur != (h,w):
  if g[cur[0]+1][cur[1]] == '#':
    cur = (cur[0]+1,cur[1])
    ts.add(cur)
  elif g[cur[0]][cur[1]+1] == '#':
    cur = (cur[0],cur[1]+1)
    ts.add(cur)
  else:
    print('Impossible')
    exit()
if ts == ss:
  print('Possible')
else:
  print('Impossible')