a,b,c,x,y=map(int,input().split())
k=min(x,y)
ans=0

AB = 2*c
if 2*c < a+b:
  ans+=AB*k
  d=x-y
  if d>=0:
    ans+=min(a*d,AB*d)
  else:
    ans+=min(b*(-d),AB*(-d))
else:
  ans+=min(a*x,AB*x)+min(b*y,AB*y)
print(ans)