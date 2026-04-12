a,b,c,x,y=map(int,input().split())
if x>y:
  ans=min(a*x+b*y,2*c*x,2*c*y+a*(x-y))
else:
  ans=min(a*x+b*y,2*c*y,2*c*x+b*(y-x))
print(ans)