H, W = map(int, input().split())
bl_H = [False for i in range(H)]
bl_W = [False for j in range(W)]

A = []
for i in range(H):
  A_i = input()
  A.append(A_i)
  for j, a in enumerate(A_i):
    if a == "#":
      bl_H[i] = True
      bl_W[j] = True

for i, h in enumerate(bl_H):
  for j, w in enumerate(bl_W):
    if h and w:
      print(A[i][j], end="")
  if h:
    print()  
