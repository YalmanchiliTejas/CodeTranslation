import math
A,B,C,x,y=map(int,input().split())
price=5000*(10**6)
for c in range(1+max([2*x,2*y])):
    a=0
    b=0
    if x>c/2:
        a=math.ceil(x-(c/2))
    if y>c/2:
        b=math.ceil(y-(c/2))
    if A*a+B*b+C*c<price:
        price=A*a+B*b+C*c
print(price)