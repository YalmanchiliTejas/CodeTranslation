n,k=open(0)
k=int(k)
d=[1]+[0]*7
for n in map(int,n[:-1]):
  p=[0]*8
  for i in range(n):
    if i<1:
      for j in range(4):
        p[j+4]+=d[j]
    else:
      for j in range(3):
        p[j+5]+=d[j]
  for i in range(10):
    if i<1:
      for j in range(4):
        p[j+4]+=d[j+4]
    else:
      for j in range(3):
        p[j+5]+=d[j+4]
  if n<1:
    for i in range(4):
      p[i]+=d[i]
  else:
    for i in range(3):
      p[i+1]+=d[i]
  d=p
print(sum(d[k::4]))