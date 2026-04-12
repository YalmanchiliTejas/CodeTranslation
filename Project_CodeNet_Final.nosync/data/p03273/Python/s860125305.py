a,b=map(int,input().split())
cc=[input() for i in range(a)]
c=[[""for i in range(b)]for j in range(a)]
for i in range(a):
  for j in range(b):
    c[i][j]=cc[i][j]
d=[]
e=0
for i in range(a):
  e=0
  for j in range(b):
    if c[i][j]=="#":
      e=1
  if e==0:
    d.append(i)
for i in d:
  c.pop(i)
  for j in range(len(d)):
    d[j]=d[j]-1
d=[]
for i in range(b):
  e=0
  for j in range(len(c)):
    if c[j][i]=="#":
      e=1
  if e==0:
    d.append(i)
for i in d:
  for j in range(len(c)):
    c[j].pop(i)
  for j in range(len(d)):
    d[j]=d[j]-1

for i in range(len(c)):
  g=""
  for j in range(len(c[i])):
    g+=c[i][j]
  print(g)