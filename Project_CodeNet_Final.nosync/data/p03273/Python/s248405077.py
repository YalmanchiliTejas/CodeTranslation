h,w=map(int,input().split())
a=[input() for i in range(h)]
b=[]
d=[]
for j in range(h):
 if int('#' in a[j])==1:b.append(a[j])
for l in range(w):
  c=0
  for k in range(len(b)):
    if list(b[k])[l]=='#':c+=1
  if c!=0:d.append(l)
for m in range(len(b)):
  x=[]
  for n in d:
    x.append(b[m][n])
  x=''.join(x)
  print(x)