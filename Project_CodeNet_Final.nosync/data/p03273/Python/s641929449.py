h, w = map(int, input().split())

pic = [""] * h
for i in range(h):
  pic[i] = input()

row = [False] * h
col = [False] * w
for i in range(h):
  for j in range(w):
    if pic[i][j] == "#":
      row[i] = True
      col[j] = True

for i in range(h):
  if row[i] == True:
    for j in range(w):
      if col[j] == True:
        print(pic[i][j], end = "")
    print()