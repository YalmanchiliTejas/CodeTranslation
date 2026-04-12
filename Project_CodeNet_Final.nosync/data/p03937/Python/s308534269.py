x,y=map(int,input().split())
failflag=0
m=[]
for i in range(x):
  m.append(input())
for i in range(x):
  for j in range(y):
    if m[i][j]=='#':
      if i<x-1 and j>0:
        if m[i+1][j-1]=='#':
          failflag=1
if failflag==0:
  print('Possible')
else:
  print('Impossible')