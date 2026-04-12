a,b,c,x,y = map(int,input().split())
ans = 0

if (a + b)/2 > c :
    price_min = c * min(x,y) * 2
    price_max = c * max(x,y) * 2

    if x-y > 0:
        price = a*(x-y) + price_min
    else:
        price = b*(y-x) + price_min

    if price > price_max:
        ans = price_max
    else:
        ans = price

else:
    ans = a * x + b * y

print(ans)
