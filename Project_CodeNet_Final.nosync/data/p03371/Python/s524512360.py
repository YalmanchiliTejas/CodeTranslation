a,b,c,x,y = map(int,input().split())

price1 = a*x+b*y

if x <= y:
    price2 = c*x*2 + (y-x)*b
else:
    price2 = c*y*2 + (x-y)*a

price3 = max(x,y)*2*c

print(min(price1,price2,price3))

