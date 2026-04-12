H,W=map(int,input().split())
A = []
hh = H
for y in range(H):
  ain = input()
  if "#" in ain:
    A.append(ain)
  else:
    hh -= 1
d = [ 0 for _ in range(W)]
for x in range(W):
  for y in range(hh):
    if A[y][x] == "#":
      break
  else:
    d[x] = 1
for y in range(hh):
  for x in range(W):
    if d[x] == 0:
        print(A[y][x], end="")
  print("")

