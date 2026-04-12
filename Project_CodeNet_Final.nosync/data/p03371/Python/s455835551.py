a,b,c,x,y = map(int,input().split())
if a+b>2*c:
  if x>y:
    print(min(a*abs(x-y)+ min(x,y)*c*2, max(x,y)*c*2))
  else:
    print(min(b*abs(x-y)+ min(x,y)*c*2, max(x,y)*c*2))
else:
  print(a*x+b*y)