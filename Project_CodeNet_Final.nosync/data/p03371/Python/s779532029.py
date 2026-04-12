a,b,ab,x,y=map(int, input().split())
if(a+b<=2*ab ):
  ans=a*x+b*y
elif(a>=2*ab and b>=2*ab):
  ans=max(x,y)*2*ab
elif(a>=2*ab):
  if(x<=y):
    ans=ab*2*x+b*(y-x)
  else:
    ans=ab*2*x
elif(b>=2*ab):
  if(x<=y):
    ans=ab*2*y
  else:
    ans=ab*2*y+a*(x-y)
elif(a+b>=2*ab):
  if(x<=y):
    ans=ab*2*x+b*(y-x)
  else:
    ans=ab*2*y+a*(x-y)
print(ans)