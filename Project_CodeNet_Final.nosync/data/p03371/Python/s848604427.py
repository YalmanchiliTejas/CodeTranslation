a,b,c,x,y=map(int,input().split())
ans=a*x+b*y
if x>y:
    AB=c*y*2 + a*(x-y)
    AB=min(AB, c*x*2)
else:
    AB=c*x*2 + b*(y-x)
    AB=min(AB, c*y*2)
print(min(ans,AB))