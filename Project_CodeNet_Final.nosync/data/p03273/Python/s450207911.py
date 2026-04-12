a,b=map(int,input().split())
c=[]
for i in range(a):
  g=input()
  if "#" not in g:
    continue
  d=list(g)
  c.append(d)
l=len(c)
p=[]
for i in range(b):
  for j in range(l):
    if c[j][i]=="#":
      p.append(i)
      break
for i in range(l):
  for j in range(len(p)):
    if j == len(p)-1:
      print(c[i][p[j]])
    else:
      print(c[i][p[j]],end="")

