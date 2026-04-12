a,b,c,x,y=map(int,input().split())
e=max(x,y)*c*2
if x>=y:
  f=y*2*c+(x-y)*a
else:
  f=x*2*c+(y-x)*b
g=x*a+y*b
print(min(e,f,g))