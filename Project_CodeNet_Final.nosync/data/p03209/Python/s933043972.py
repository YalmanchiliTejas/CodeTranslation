n,x=map(int,input().split())
l=[0]
for i in range(n):
  l.append(2**(i+1)-1)
m=[0]
for i in range(n+1):
  m.append(2**(i+2)-3)
c=0
for i in range(n,-1,-1):
  t=2**(i+1)-1
  if x<t:
    x-=1
  elif x==t:
    c+=l[i]+1
    x=0
  else:
    c+=l[i]+1
    if x==m[i+1]:
      x-=1
    x=x-t
print(c)