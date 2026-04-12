n,x,m=map(int,input().split())
a=set()
b=[x]
for i in range(m):
  x=pow(x,2,m)
  if x in a:break
  a.add(x)
  b+=[x]
j=b.index(x)
n-=j
c=b[j:]
ans=sum(b[:j])+sum(c)*(n//len(c))+sum(c[:n%len(c)])
print(ans)