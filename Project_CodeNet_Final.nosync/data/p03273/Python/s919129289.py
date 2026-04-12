H, W = map(int, input().split())
A = [''] * H
for i in range(H):
  A[i] = input()

num_col_white = [0] * W
for i in range(H):
  for j in range(W):
    if A[i][j] == '.':
      num_col_white[j] += 1

for i in range(H):
  if A[i].count('.') == W:
    continue
  row = ''
  for j in range(W):
    if num_col_white[j] != H:
      row += A[i][j]
  print(row)
