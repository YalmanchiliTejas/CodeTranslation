a,b,c,x,y = map(int, input().split())

price = 0
if (c*2 > a+b):
    price += a*x + b*y
else:
    if (x > y):
        price = c*2 * y
        if(c*2 < a):
            price += c*2 * (x-y)
        else:
            price += a * (x-y)
    else:
        price = c*2 * x
        if(c*2 < b):
            price += c*2 * (y-x)
        else:
            price += b * (y-x)
            
print(price)