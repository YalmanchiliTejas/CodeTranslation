def check(h, w):
  if A[h][w] != r:
    return True
  if h == H - 1 and w == W - 1:
    return True
  cnt = 0
  if h + 1 < H:
    cnt += A[h + 1][w] == r
  if w + 1 < W:
    cnt += A[h][w + 1] == r
  if cnt != 1:
    return False
  if h == 0 and w == 0:
    return True
  cnt = 0
  if h - 1 >= 0:
    cnt += A[h - 1][w] == r
  if w - 1 >= 0:
    cnt += A[h][w - 1] == r
  if cnt == 0:
    return False
  return True

H, W = list(map(int, input().split()))
A = [list(input()) for _ in range(H)]
r = "#"

for i in range(H):
  for j in range(W):
    if not check(i, j):
      print("Impossible")
      exit()

print("Possible")