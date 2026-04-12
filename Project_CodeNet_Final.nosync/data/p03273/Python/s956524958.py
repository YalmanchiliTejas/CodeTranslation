H,W=map(int,input().split())
a=[]
for _ in range(H):
  a.append(list(map(lambda x: 1 if x=="#" else 0,list(input()))))
#print(a)

b=[]
for i in range(H):
  if sum(a[i])!=0:
    b.append(a[i])
#print(b)

c=[]
for j in range(W):
  cnt=0
  for i in range(len(b)):
    cnt+=b[i][j]
  c.append(cnt)
#print(c)

d=[]
for i in range(len(b)):
  dd=[]
  for j in range(W):
    if c[j]!=0:
      dd.append(b[i][j])
  d.append(dd)
#print(d)

for i in range(len(d)):
  print("".join(list(map(lambda x: "." if x==0 else "#",d[i]))))