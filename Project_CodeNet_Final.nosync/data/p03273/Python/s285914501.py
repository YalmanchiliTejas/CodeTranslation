H,W=map(int,input().split())

d=[]
memo=[0]*W
for i in range(H):
  row=list(str(input()))
  if '#' in row:
    d.append(row)
  for j in range(W):
    if row[j] == '#':
      memo[j] = 1

for i in range(len(d)):
  for j in range(W):
    if memo[j] == 1:
      print(d[i][j],end='')
  print()
