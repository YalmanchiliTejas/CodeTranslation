h,w = map(int,input().split())
A = [input() for _ in range(h)]
D  = ((0,1), (1,0))

from collections import deque
queue = deque([((0,0), [])])

cand = []
while queue:
  p, path = queue.popleft()
  x, y = p
  path = path + [p]
  for dx,dy in D:
    nx,ny = x+dx, y+dy
    if not (0<=nx < h and 0<= ny < w):
      continue
    if A[nx][ny] != '#':
      continue
    if nx == h-1 and ny == w-1:
      cand.append(path+[(nx,ny)])
      continue
    queue.append(((nx,ny),path))

for c in cand:
  for i in range(h):
    for j in range(w):
      if A[i][j] == '.':
        continue
      elif (i,j) not in c:
        break
    else:
      continue
    break
  else:
    print('Possible')
    break
else:
  print('Impossible')
    