n,m = map(int,input().split())
lis = []
for i in range(n):
  lis.append(str(input()))
tate = [0]*n
yoko = [0]*m
for k in range(n):
  for h in range(m):
    if lis[k][h] == "#":
      tate[k] = 1
      yoko[h] = 1
li = []
cou = n
for i in range(n):
  s = []
  for k in range(m):
    if tate[i] != 0 and yoko[k] != 0:s.append(lis[i][k])
  if s == []:
    cou -= 1
  else:
    li.append(s)
for i in range(cou):print("".join(li[i]))