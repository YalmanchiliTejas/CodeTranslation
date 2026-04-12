tate,yoko=map(int,input().split())
b=[]
for i in range(tate):
  b.append(list(input()))
tatecheck=[]
for i in range(tate):
  flag=1
  for j in range(yoko):
    if b[i][j]=='#':
      flag=0
      break
  if flag==1:
    tatecheck.append(i)
tatecheck.reverse()
for i in tatecheck:
  del b[i]
yokocheck=[]
tate=len(b)
yoko=len(b[0])
for i in range(yoko):
  flag=1
  for j in range(tate):
    if b[j][i]=='#':
      flag=0
      break
  if flag==1:
    yokocheck.append(i)
yokocheck.reverse()
for i in yokocheck:
  for j in range(tate):
    del b[j][i]
tate=len(b)
for i in range(tate):
  print("".join(b[i]))