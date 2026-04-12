H, W = map(int,input().split())
a = [list(input()) for i in range(H)]
b = []
c = []
for y in range(H):
  if "#" in a[y]:
    b.append(a[y])
for row in zip(*b):
  if "#" in row:
    c.append(row)
for row in zip(*c):
  print("".join(row))