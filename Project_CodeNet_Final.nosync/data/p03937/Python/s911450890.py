H, W = map(int, input().split())
A = []
c = 0
for i in range(H):
  As = input()
  A.append(As)
  c += As.count("#")
if c != H+W-1:
  print("Impossible")
  exit()
ok = True
i, j = (0, 0)
for k in range(H+W-2):
  fR = j+1 < W and A[i][j+1] == "#"
  fD = i+1 < H and A[i+1][j] == "#"
  if not fR ^ fD:
    ok = False
    break
  if fR:
    j += 1
  if fD:
    i += 1
if ok:
  print("Possible")
else:
  print("Impossible")
