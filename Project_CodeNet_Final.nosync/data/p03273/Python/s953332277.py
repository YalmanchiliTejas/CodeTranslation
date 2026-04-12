H, W = map(int, input().split())
A = [input() for _ in range(H)]

h_check = [0] * H
w_check = [0] * W

for i in range(H):
  for j in range(W):
    if A[i][j] == ".":
      h_check[i] += 1
      w_check[j] += 1

h_check = list(map(lambda x: 1 - x // W, h_check))
w_check = list(map(lambda x: 1 - x // H, w_check))

for i in range(H):
  if h_check[i]:
    tmp = ""
    for j in range(W):
      if w_check[j]:
        tmp += A[i][j]
    print(tmp)