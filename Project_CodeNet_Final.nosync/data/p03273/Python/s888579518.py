H, W = map(int, input().split())
S = [input() for i in range(H)]
h, w = [True for _ in range(H)], [True for _ in range(W)]
for i in range(H):
  cnt = 0
  for j in range(W):
    if S[i][j] == '.':
      cnt += 1
  if cnt == W:
    h[i] = False
for i in range(W):
  cnt = 0
  for j in range(H):
    if S[j][i] == '.':
      cnt += 1
  if cnt == H:
    w[i] = False
for i in range(H):
  if h[i]:
    T = ""
    for j in range(W):
      if w[j]:
        T = T[:] + S[i][j]
    print(T)