n,x,m=map(int,input().split())
ary=[x]
ans=x
d={x:0}
i=1
while x and i<n and (x**2)%m not in d:
  x=(x**2)%m
  ans+=x
  d[x]=i
  ary.append(x)
  i+=1
if x==0 or i==n:
  print(ans)
  exit()
s=d[(x**2)%m]
l=i-s
suml=sum(ary[s:])
tmp=n-i
ans+=suml*(tmp//l)
ans+=sum(ary[s:s+tmp%l])
print(ans)