H,W=map(int,input().split())

BW=[]
for i in range(H):
  nextline=list(input())
  for j in range(W):
    if nextline[j]=='#':
      BW.append(nextline)
      break;

columnWlist=[1]*(W)
for i in range(len(BW)):
  for j in range(W):
    if columnWlist[j]==1 and BW[i][j]=='#':
      columnWlist[j]=0

for i in range(len(BW)):
  for j in range(W-1,-1,-1):
    if columnWlist[j]==1:
      BW[i].pop(j)
      
for i in range(len(BW)):
  for j in range(len(BW[0])):
    print(BW[i][j],end='')
  print()