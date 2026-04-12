h, w = map(int , input().split())

ahw = []
for i in range(h):
  aw = [a for a in input()]
  ahw.append(aw)

row = [False] * h
column = [False] * w
for i in range(h):
  for j in range(w):
    if ahw[i][j] == "#" :
      row[i] = True
      column[j] = True

for i in range(h):
  if row[i] :
    for j in range(w):
      if column[j]:
        print(ahw[i][j],end = "")
    print()
    

  