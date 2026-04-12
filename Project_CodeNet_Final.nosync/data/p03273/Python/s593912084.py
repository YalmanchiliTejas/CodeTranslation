h,w = map(int,input().split())
sl = [input() for _ in [0]*h]
l = []
for i in range(len(sl)):
  if sl[i].count('#') > 0:
    l.append(i)
sl = [sl[i] for i in l]
l = []
for j in range(len(sl[0])):
  flag = False
  for i in range(len(sl)):
    if sl[i][j] == '#':
      flag = True
  if flag == True:
    l.append(j)
for s in sl:
  s = [s[j] for j in l]
  print(''.join(s))