H,W=map(int,input().split())
a = [input() for i in range(H)]
b = []
for i in range(H):
  if a[i].count('.')!=W:
    b.append(a[i])

flags=[False]*W

for i in range(H):
  for j in range(W):
    if a[i][j] != '.':
      flags[j]=True

for i in range(len(b)):
  tmp=[]
  for j in range(W):
    if flags[j]:
      tmp.append(b[i][j])
  print(''.join(tmp))
    