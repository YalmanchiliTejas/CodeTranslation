H,W = map(int,input().split())
a = []
for i in range(H):
  a.append(input())

yoko = []
tate = []

for i in range(H):
  if a[i] != "."*W:
    yoko.append(i)
for i in range(W):
  c = 0
  for j in range(H):
    if a[j][i] == "#":
      c = 1
  if c == 1:
    tate.append(i)

for y in yoko:
  s = ""
  for t in tate:
    s += a[y][t]
  print(s)  