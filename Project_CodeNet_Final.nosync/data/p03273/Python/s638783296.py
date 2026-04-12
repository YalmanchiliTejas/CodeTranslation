h, w = list(map(int, input().split()))
a = [input() for i in range(h)]

row = [False]*h
cow = [False]*w

for i in range(h):
  for j in range(w):
    if a[i][j] == "#":
      row[i] = True
      cow[j] = True
      
for i in range(h):
  if row[i]: 
    for j in range(w):
      if cow[j]:
        print(a[i][j], end="")
 
    print()