a,b,c,x,y=map(int,input().split())
ans=0
if a+b<c*2:
  ans=a*x+b*y
else:
  ans+=min(x,y)*c*2
  if x > y:
    ans+=(x-y)*a
  else:
    ans+=(y-x)*b
  if ans > max(x,y)*c*2:
    ans=max(x,y)*c*2
print(ans)