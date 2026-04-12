a,b,c,x,y=map(int,input().split())
X=x
Y=y
MIN=10**9
while True:
    sum_=a*x+b*y+2*c*(max(X-x,Y-y))
    MIN=min(MIN,sum_)
    if x==0 and y==0:
        break
    if x>0:
        x-=1
    else:
        x=0
    if y>0:
        y-=1
    else:
        y=0
print(MIN)