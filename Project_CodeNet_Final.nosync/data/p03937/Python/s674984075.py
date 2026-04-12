from collections import deque
H, W = map(int, input().split())
S = []
for i in range(H):
  S.append(input())
num = 0
for i in range(H):
  for j in range(W):
    if S[i][j] == "#":
      num += 1
A = [[0 for j in range(W)] for i in range(H)]
d = deque([[0, 0]])
while len(d) > 0:
  x = d.pop()
  A[x[0]][x[1]] = 1
  if x[0] + 1 < H and S[x[0]+1][x[1]] == "#":
    d.append([x[0]+1, x[1]])
  if x[1] + 1 < W and S[x[0]][x[1]+1] == "#":
    d.append([x[0], x[1]+1])
if num == H + W - 1 and A[H-1][W-1] == 1:
  print("Possible")
else:
  print("Impossible")