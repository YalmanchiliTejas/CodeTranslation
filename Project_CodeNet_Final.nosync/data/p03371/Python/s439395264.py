import math
a,b,c,x,y=map(int,input().split())
cost=float('inf')
if 2*c>=a+b:
    cost=a*x+b*y
else:
    least=min(x*2,y*2)
    most=max(x*2,y*2)
    r=least
    while r<=most:
        p=max(0,math.ceil(x-r/2))
        q=max(0,math.ceil(y-r/2))
        tmp=a*p+b*q+c*r
        cost=min(cost,tmp)
        r+=1
print(cost)