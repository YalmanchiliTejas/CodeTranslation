a,b,c,x,y=map(int,input().split())
c*=2
d=a*x+b*y
f=max(x,y)*c
if x<y:
  
  e=x*c+(y-x)*b
else:
  z=x-y
  e=y*c+(x-y)*a
print(min(d,min(e,f)))
