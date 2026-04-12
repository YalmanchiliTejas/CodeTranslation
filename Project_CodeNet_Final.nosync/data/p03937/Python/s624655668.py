import sys
H,W = [int(i) for i in input().split()]
A = [list(input().strip()) for j in range(H)]

q = [(0,0)]
while q:
  h,w = q.pop()
  if (h,w) == (H-1,W-1):
    A[h][w] = '.'
    break
  for dh,dw in [(1,0),(0,1)]:
    nh,nw = h+dh,w+dw
    if 0 <= nh < H and 0 <= nw < W and A[nh][nw] == '#':
      q.append((nh,nw))
      A[h][w] = '.'
      break
  else:
    print('Impossible')
    sys.exit()

for h in range(H):
  for w in range(W):
    if A[h][w] == '#':
      print('Impossible')
      sys.exit()
print('Possible')