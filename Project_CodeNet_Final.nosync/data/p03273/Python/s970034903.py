h,w = map(int,input().split())
temp = []
for _ in range(h):
  l = list(input())
  if l.count('#')!=0:
    temp.append(l)
h = len(temp)
#print(temp)
cols = []
for j in range(w):
  valid = False
  for i in range(h):
    if temp[i][j]=='#':
      valid = True
  if not valid:
    cols.append(j)
for i in range(h):
  for j in range(w):
    if j not in cols:
    	print(temp[i][j],end='')
  print()