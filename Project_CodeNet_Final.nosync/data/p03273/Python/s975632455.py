H,W=map(int,input().split())
row=[False]*H
col=[False]*W
b=['']*H
for i in range(H):
  a=input()
  b[i]=a
  for j in range(W):
    if a[j]=='#':
      row[i]=True
      col[j]=True
for i in range(H):
  if row[i]:
    for j in range(W):
      if col[j]:
        if row[i] and col[j]:
          print(b[i][j],end='')
    print()