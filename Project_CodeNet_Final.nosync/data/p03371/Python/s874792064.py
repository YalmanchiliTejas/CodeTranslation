a,b,c,x,y = list(map(int, input().split()))

price1 = a*x + b*y


if(x>y):
    price2 = y*2*c + (x-y)*a
    price3 = x*2*c
else:
    price2 = x*2*c + (y-x)*b
    price3 = y*2*c

print(min(price1,price2,price3))