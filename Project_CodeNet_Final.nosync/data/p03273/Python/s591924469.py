h,w=map(int,input().split())
lis=[]
for i in range(h):
  lis.append(input())
tate=[]
yoko=[]
for i in range(0,w):
  for j in range(0,h):
    if lis[j][i]=="#":
      tate.append(i)
      break

for i in range(0,h):
  for j in range(0,w):
    if lis[i][j]=="#":
      yoko.append(i)
      break

for x in yoko:
  for y in tate:
    if y != tate[len(tate)-1]:
      print(lis[x][y],end="")
    else:
      print(lis[x][y])