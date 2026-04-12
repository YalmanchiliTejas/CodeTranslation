H, W = map(int, input().split())
A = []
for i in range(H):
  a = [i for i in str(input())]
  A.append(a)
  
def meiro(A, h, w):
  global H
  global W
  if ('#' in A[h][:w]) or (A[h][w] != '#'):
    return False
  while A[h][w] == '#':
    w += 1
    if w == W:
      break
  if h==H-1 and w==W:
    return True
  elif h == H-1:
    return False
  elif A[h][w-1:].count('#')==1:
    return meiro(A, h+1, w-1)
  
if meiro(A, 0, 0):
  print('Possible')
else:
  print('Impossible')