A,B,C,X,Y=map(int,input().split())
price=0
if A+B>C+C:
    minXY=min(X,Y)
    price+=minXY*C*2
    X-=minXY
    Y-=minXY
if A>C+C:
    price+=X*2*C
    X=0
else:
    price+=A*X
    X=0
if B>C+C:
    price+=Y*2*C
    Y=0
else:
    price+=B*Y
    Y=0
print(price)