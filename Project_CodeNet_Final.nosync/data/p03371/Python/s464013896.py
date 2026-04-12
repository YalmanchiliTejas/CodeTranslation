a,b,c,x,y = map(int,input().split())
price1 = 0
price2 = 0
price = 0
if (a+b) >= c*2:
    price1 += min(x,y) * 2 * c
    if min(x,y)==x:
        price1 += (y-x)*b
    else:
        price1 += (x-y)*a
        
    price2 += c * max(x,y) *2
    price = min(price1,price2)
else:
    price += (a*x + b*y)
print(price)