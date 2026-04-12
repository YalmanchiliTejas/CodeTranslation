a,b,c,x,y=map(int,input().split())
if a+b<=c*2:
  print(a*x+b*y)
else:
  z=min(x,y)
  ans=(c*2)*z
  x-=z;y-=z
  ans+=min((x+y)*2*c,x*a+y*b)
  print(ans)