a,b,c,x,y=map(int,input().split())
if 2*c>=a+b:
  print(a*x+b*y)
else:
  if 2*c<=a:
    if x>=y:
      print(2*x*c)
    else:
      if 2*c<=b:
        print(2*y*c)
      else:
        print(2*x*c+(y-x)*b)
  elif 2*c<=b:
    if y>=x:
      print(2*y*c)
    else:
      if 2*c<=a:
        print(2*x*c)
      else:
        print(2*y*c+(x-y)*a)
  else:
    if x<=y:
      print(2*c*x+(y-x)*b)
    else:
      print(2*c*y+(x-y)*a)