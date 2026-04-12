a,b,c,x,y=map(int,input().split())
ans=a*x+b*y
if x<y:
  ans=min(ans,x*2*c+(y-x)*b)
  ans=min(ans,y*2*c)
else:
  ans=min(ans,y*2*c+(x-y)*a)
  ans=min(ans,x*2*c)
print(ans)