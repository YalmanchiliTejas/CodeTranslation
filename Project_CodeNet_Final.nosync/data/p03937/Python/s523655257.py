H,W = map(int,input().split())
A = [None for _ in range(H)]
for i in range(H):
  A[i] = input()

count = 0

for i in range(H):
  for j in range(W):
    if A[i][j] == '#':
      count += 1

if count == H+W-1:
  print('Possible')
else:
  print('Impossible')