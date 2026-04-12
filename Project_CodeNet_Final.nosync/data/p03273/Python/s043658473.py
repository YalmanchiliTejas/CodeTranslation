h,w = map(int,input().split())
a = [""]*h
for i in range(h):
  a[i] = input()

row = [False]*h
column = [False]*w

for i in range(h):
  for j in range(w):
    if a[i][j] == "#":
      row[i] = True
      column[j] = True

for i in range(h):
  if row[i]:
    for j in range(w):
      if column[j]:
        print(a[i][j],end = "")
    print()
        
    
      
