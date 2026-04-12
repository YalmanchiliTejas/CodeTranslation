n,x,m=map(int,input().split())
l,s=[0]*m,[0]*m
t=p=0
while l[x]<1:
  t+=1
  l[x]=t
  s[x]=s[p]+x
  p=x
  x=p*p%m
k=l[x]
d,m=divmod(n-k,t+1-k)
print((s[p]+x-s[x])*d+s[l.index(k+m)])