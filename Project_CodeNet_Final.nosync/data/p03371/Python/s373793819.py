a,b,c,x,y=map(int,input().split())
k=min(x,y)
ans=0

if 2*c < a+b:
  ans+=2*c*k
  d=x-y
  if d>=0:
    ans+=min(a*d,2*c*d)
  else:
    ans+=min(b*(-d),2*c*(-d))
else:
  ans+=min(a*x,2*c*x)+min(b*y,2*c*y)
print(ans)