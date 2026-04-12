h,w=map(int,input().split())
a=[input() for i in range(h)]
row=[False]*h
col=[False]*w
for i in range(h):
  for j in range(w):
    if a[i][j]=="#":
      row[i]=True
      col[j]=True
for i in range(h):
  for j in range(w):
    if row[i]==True and col[j]==True:
      print(a[i][j],end="")
  if row[i]:
    print()