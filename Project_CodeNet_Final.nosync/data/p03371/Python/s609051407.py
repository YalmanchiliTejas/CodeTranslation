a,b,c,x,y=map(int,input().split())
p1=a*x+b*y
p2=max(x,y)*c*2
if x>y:
    p3=y*c*2+(x-y)*a
else:
    p3=x*c*2+(y-x)*b
print(min(p1,p2,p3))
