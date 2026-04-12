n,x,m=map(int,input().split())
l=[0]*m
s=[0]*m
t=p=0
while l[x]<1:
  t+=1
  l[x]=t
  s[x]=s[p]+x
  p=x
  x=pow(p,2,m)
T=t+1-l[x]
S=s[p]+x-s[x]
d,m=divmod(n-l[x],T)
print(S*d+s[l.index(l[x]+m)])