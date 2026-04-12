h,w = map(int,input().split())
a = [input() for _ in range(h)]
b = 0
check = True
for i in range(h):
  for j in range(w):
    if b == j:
      if a[i][j] == ".":
        check = False
    elif b+1 == j:
      if a[i][j] == "#":
        b = j
    else:
      if a[i][j] == "#":
        check = False
  if not check:
    break
if check:
  print("Possible")
else:
  print("Impossible")