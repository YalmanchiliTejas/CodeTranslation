a,b,c,x,y = map(int,input().split())

if x>=y:
  value = 2*y*c+(x-y)*a
else:
  value = 2*x*c+(y-x)*b
print(min(a*x+b*y,2*c*max(x,y),value))
