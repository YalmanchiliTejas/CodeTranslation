n,x,m=map(int,input().split())
l=[-1]*m
s=[0]*m
t=p=0
while l[x]<0:
  t+=1
  l[x]=t
  s[x]=s[p]+x
  p=x
  x=pow(p,2,m)
T=t+1-l[x]
S=s[p]+x-s[x]
if n<l[x]:
  print(s[l.index(n)])
else:
  print(S*((n-l[x])//T)+s[l.index(l[x]+(n-l[x])%T)])