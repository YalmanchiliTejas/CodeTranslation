a,b,c,x,y=map(int,input().split())
p1=a*x+b*y
p2=x*c*2
if x<y:
  p2+=(y-x)*b
p3=y*c*2
if y<x:
  p3+=(x-y)*a
p4=c*max(x,y)*2
print(min(p1,p2,p3,p4))