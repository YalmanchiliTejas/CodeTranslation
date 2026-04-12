a,b,c,x,y=map(int,input().split())
ans=x*a+y*b
if x>=y:
  ans=min(ans,c*min(x,y)*2+a*(x-y))
else:
  ans=min(c*min(x,y)*2+b*(y-x),ans)
ans=min(c*max(x,y)*2,ans)
print(ans)
