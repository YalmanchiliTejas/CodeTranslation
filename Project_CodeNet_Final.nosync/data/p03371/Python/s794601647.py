a,b,c,x,y=map(int,input().split())
if a+b<=2*c:print(a*x+b*y)
else:
  if x<y:print(x*2*c+(y-x)*min(b,2*c))
  else:print(y*2*c+(x-y)*min(a,2*c))