a,b,c,x,y=map(int,input().split())
ans=0
if y>x:
  ans+=(y-x)*b
else:
  ans+=(x-y)*a
if a+b>c*2:
  print(min(min(x,y)*2*c+ans,max(x,y)*2*c))
else:
  print(a*x+b*y)