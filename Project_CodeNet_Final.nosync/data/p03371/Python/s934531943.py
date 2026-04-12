a,b,c,x,y=map(int,input().split())
one = a*x+b*y
if x>y:
  two=2*c*y+a*(x-y)
else:
  two=2*c*x+b*(y-x)
three = 2*max(x,y)*c
print(min(one,two,three))