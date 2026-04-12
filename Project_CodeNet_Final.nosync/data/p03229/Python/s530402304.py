n=int(input())
a=[int(input())for _ in range(n)]
if n==2:print(abs(a[0]-a[1]));exit()
f=[-1]
for i in range(1,n-1-(n%2==0)):
  if i%2:f.append(2)
  else:f.append(-2)
if n%2:f+=[-1]
else:f+=[-2,1]
b=[]
c=[]
for i in f:
  b.append(i)
  c.append(-i)
b.sort()
c.sort()
sb=sc=0
a.sort()
for i in range(n):
  sb+=a[i]*b[i]
  sc+=a[i]*c[i]
print(max(sb,sc))
