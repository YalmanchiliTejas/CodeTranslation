h,w=map(int,input().split())
a=[]
for i in range(h):
  tmp=input()
  if len(tmp)!=tmp.count('.'):
    a.append(tmp)
  else:
    h-=1

b=[]
for i in range(w):
  cnt=0
  for j in range(h):
    if a[j][i]=='.':
      cnt+=1
  if cnt==h:
    b.append(0)
  else:
    b.append(1)

for i in range(h):
  for j in range(w):
    if b[j]:
      print(a[i][j], end='')
  print()
      