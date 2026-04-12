H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

L = []
R = []

for i in range(H):
  R_cnt = 0
  for j in range(W):
    if A[i][j] == '.':
      R_cnt += 1
  if R_cnt == W:
    R.append(i)

for j in range(W):
  L_cnt = 0
  for i in range(H):
    if A[i][j] == '.':
      L_cnt += 1
  if L_cnt == H:
    L.append(j)

for i in range(H):
  S = []
  for j in range(W):
    if i in R:
      break
    elif j in L:
      continue
    else:
      S.append(A[i][j])
  if len(S) > 0:
    print(''.join(S))
