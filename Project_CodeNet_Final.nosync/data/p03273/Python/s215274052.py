H, W = map(int, input().split())
A = [input() for _ in range(H)]

h_check = [0] * H
w_check = [0] * W

for i in range(H):
  flag = 0
  for j in range(W):
    if A[i][j] != ".":
      flag = 1
      break
  h_check[i] = flag

for j in range(W):
  flag = 0
  for i in range(H):
    if A[i][j] != ".":
      flag = 1
      break
  w_check[j] = flag

for i in range(H):
  if h_check[i]:
    tmp = ""
    for j in range(W):
      if w_check[j]:
        tmp += A[i][j]
    print(tmp)