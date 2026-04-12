import sys
input=sys.stdin.readline
a,b,c,x,y=map(int,input().split())
money1=a*x+b*y
money2=min(x,y)*2*c+(x-min(x,y))*a+(y-min(x,y))*b
money3=max(x,y)*c*2
print(min(money1,money2,money3))