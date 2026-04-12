H,W = map(int,input().split())
A = [list(input()) for _ in range(H)]
for h in range(H):
  if A[h].count('.') == W:
    for w in range(W):
      A[h][w] = ''
for h in range(H):
  for w in range(W):
    if A[h][w] == '.':
      for i in range(H):
        if A[i][w] == '#':
          break
        if i == H-1:
          for j in range(H):
            A[j][w] = ''

for i in range(H):
  if ''.join(A[i]) == '':
    continue
  print(''.join(A[i]))