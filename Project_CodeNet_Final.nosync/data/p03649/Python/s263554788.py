n,*a=map(int,open(0).read().split())
c=0
while 1:
  m=max(a)
  if m<n:break
  t,f=m//n,1
  c+=t
  for i,b in enumerate(a):
    if b==m and f:
      a[i]%=n
      f=0
    else:
      a[i]+=t
print(c)