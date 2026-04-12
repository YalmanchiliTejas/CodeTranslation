from collections import deque

H, W = map(int, input().split())
Map = [input() for _ in range(H)]

slst = [[] for _ in range(H)]
for i in range(H):
  for j in range(W):
    if Map[i][j] == '#':
      slst[i].append(j)

m = 0
for i in range(1,H):
  if slst[i-1][-1] != slst[i][0]:
    print('Impossible')
    exit()
    
print('Possible')