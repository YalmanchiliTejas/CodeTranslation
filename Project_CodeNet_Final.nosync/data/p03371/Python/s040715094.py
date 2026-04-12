a,b,c,x,y = list(map(int,input().split()))
for i in range(100001):
    price_new = i*2*c + max(0, x-i)*a + max(0, y-i)*b
    if i==0:
        price = price_new
    else:
        price = min(price, price_new)

print(price)