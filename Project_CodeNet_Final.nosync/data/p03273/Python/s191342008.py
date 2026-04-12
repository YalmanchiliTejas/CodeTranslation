h,w=map(int,input().split())
l=[input() for i in range(h)]
m=[]
for i in range(h):
  if l[i]=='.'*w:
    m.append(i)
for x in m[::-1]:
  del l[x]
m=[]
for i in range(w):
  now=0
  for j in range(len(l)):
    if l[j][i]=='.':
      now+=1
  if now==len(l):
    m.append(i)
for x in m[::-1]:
  for i in range(len(l)):
    l[i]=l[i][:x]+l[i][x+1:]
[print(x) for x in l]