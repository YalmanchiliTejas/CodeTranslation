H,W=map(int,input().split())
a=[[""]*W for i in range(H)]
for i in range(H):
  a[i]=list(input())
row=[False]*H
col=[False]*W
for i in range(H):
  for j in range(W):
    if a[i][j]=="#":
      row[i]=True
      col[j]=True
for i in range(H):
  if row[i]==True:
    for j in range(W):
      if col[j]==True:
        print(a[i][j],end="")
    print("")
