a,b,c,x,y=map(int,input().split())
if a+b<=2*c:
  print(a*x+b*y)
elif x>=y:
  print(min(y*2*c+(x-y)*a,x*2*c))
else:
  print(min(x*2*c+(y-x)*b,y*2*c))