a,b,c,x,y=map(int,input().split())

if a+b<=2*c:
  print(a*x+b*y)
elif x>y:
  if a<=2*c:
    print(y*(2*c)+(x-y)*a)
  else:
    print(x*2*c)
else:
  if b<=2*c:
    print(x*(2*c)+(y-x)*b)
  else:
    print(y*2*c)