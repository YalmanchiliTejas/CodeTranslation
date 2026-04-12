h,w=map(int,input().split())
a=[[j for j in input()] for i in range(h)]

b=[]
for x in a:
  if "#" in x:
    b.append(x)

c=[]
for y in zip(*b):
  if "#" in y:
    c.append(y)
c1=[]
c1=zip(*c)
    
#c=zip(*[y for y in zip(*b) if "#" in y])

for d in c1:
  print("".join(d))