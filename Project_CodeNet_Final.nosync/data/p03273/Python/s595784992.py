h,w = list(map(int,input().split()))
a = [[i for i in input()] for _ in range(h)]
remove = []
for r in range(h):
  flag = True
  for c in range(w):
    if a[r][c] == "#":
      flag = False
      break
  if flag:
    remove.append(r)
for i in range(len(remove)):
  a.pop(remove[i])
  remove = [j-1 for j in remove]
remove = []
for c in range(w):
  flag = True
  for r in range(len(a)):
    if a[r][c] == "#":
      flag = False
      break
  if flag:
    remove.append(c)
for c in range(len(remove)):
  for r in range(len(a)):
    a[r].pop(remove[c])
  remove = [i-1 for i in remove]
  
for r in range(len(a)):
  print("".join(a[r]))