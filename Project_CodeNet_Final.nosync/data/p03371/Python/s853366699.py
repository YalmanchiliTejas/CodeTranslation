a,b,c,x,y=map(int, input().split())
if a+b<=c*2:
    price=a*x+b*y
elif x<=y:
    price=c*2*x + b*(y-x)
    if price>=c*2*y:
        price=c*2*y
else:
    price=c*2*y + a*(x-y)
    if price>=c*2*x:
        price=c*2*x
print(price)