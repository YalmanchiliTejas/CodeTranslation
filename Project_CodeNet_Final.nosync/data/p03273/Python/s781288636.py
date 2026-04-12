h,w = map(int,input().split())
maze = []
for _ in range(h):
  s = input()
  if s != '.'*w:
    maze.append(s)
h = len(maze)
skip = []
for j in range(w):
  for i in range(h):
    if maze[i][j] == '#':
      break
  else:
    skip.append(j)
 
for i in range(h):
  for j in range(w):
    if j not in skip:
      print(maze[i][j],end= '')
  print()