h,w = map(int,input().split())
meiros = [['' for x in range(w)] for y in range(h)]
for i in range(h):
  tmp = input().rstrip()
  for j in range(w):
    meiros[i][j] = tmp[j]
nowh,noww = 0,0
queue = [(0,0)]
flg = True
while 1:
  L = len(queue)
  if L == 0:
    break
  for z in range(L):
    nowh,noww = map(int,queue[0])
    queue.pop(0)
    if nowh + 1 < h:
      if meiros[nowh+1][noww] == '#':
        queue.append((nowh+1,noww))
    if noww + 1 < w:
      if meiros[nowh][noww+1] == '#':
        queue.append((nowh,noww+1))
    meiros[nowh][noww] = '.'
  if nowh != (h-1) and noww != (w-1) and len(queue) != L:
    flg = False
    break
for mairo in meiros:
  if '#' in mairo:
    flg = False
    break
if flg:
  print('Possible')
else:
  print('Impossible')