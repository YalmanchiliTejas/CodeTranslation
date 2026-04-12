import sys
input = sys.stdin.readline
a,b,c,x,y=map(int,input().split())

c1=a*x+b*y
if x>=y:
    c2=2*y*c+(x-y)*a
else:
    c2=2*x*c+(y-x)*b
c3=2*max(x,y)*c
print(min(c1,c2,c3))
