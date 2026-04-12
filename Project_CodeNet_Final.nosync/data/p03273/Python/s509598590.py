n,m=map(int,input().split())
l=[]
for i in range(n):
  l1=list(input())
  b=True
  for j in l1:
    if j=="#":
      b=False
  if b==False:
    l.append(l1)
for i in range(m):
  b=True
  for j in range(len(l)):
    if l[j][m-1-i]=="#":
      b=False
  if b:
    for j in range(len(l)):
      del l[j][m-1-i]
for i in range(len(l)):
  print("".join(l[i]))