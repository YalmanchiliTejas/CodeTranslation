a,b,c,x,y = map(int,input().split())
min = x if x<y else y
price=0
if a+b > 2*c:
    price = min*2*c
    if a < c*2 and y<x:
        price+=a*(x-y)
    elif b<c*2 and x<y:
        price+=b*(y-x)
    else:
        diff = y-x if x<y else x-y
        price+=2*c*(diff)
else:
    price = a*x+b*y
print(price)