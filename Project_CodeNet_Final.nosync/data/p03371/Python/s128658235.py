a,b,c,x,y=map(int,input().split())
cost=0
val=min(x,y)
x-=val
y-=val
if a+b>=2*c:
    cost+=val*2*c
else:
    cost+=val*a
    cost+=val*b
if x:
    cost+=x*min(a,2*c)
if y:
    cost+=y*min(b,2*c)
print(cost)

