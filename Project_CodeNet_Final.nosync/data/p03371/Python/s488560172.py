a,b,c,x,y = map(int,input().split())
ab = a*x+b*y
if x==y:
  conly = c*x*2
  print(min(ab,conly))
elif x>y:
  conly = c*x*2
  ac = c*y*2+(x-y)*a
  print(min(ab,conly,ac))
else:
  conly = c*y*2
  bc = c*x*2+(y-x)*b
  print(min(ab,conly,bc))