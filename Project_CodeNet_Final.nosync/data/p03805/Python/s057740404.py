n,m=[int(i) for i in input().split()]
es=set()
for _ in range(m):
    u,v=map(int,input().split())
    u,v=u-1,v-1
    es|={(u,v),(v,u)}

p=[[0]]
x=0
while p:  
  p1=p.pop()
  if len(p1)==n:
    x+=1
  else:
    for l0,l1 in es:
      if l0==p1[len(p1)-1] and l1 not in p1:
          p.append(p1+[l1])

print(x)