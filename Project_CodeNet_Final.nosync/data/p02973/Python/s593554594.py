n=int(input())
c=[]
hc=0
for i in range(n):
  a=int(input())
  l,r=-1,hc
  while r-l!=1:
    t=(l+r)//2
    if c[t]<a:
      r=t
    else:
      l=t
  if r==hc:
    c.append(a)
    hc+=1
  else:
    c[r]=a
print(hc)