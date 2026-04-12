a,b,c,x,y = map(int, input().split(" "))

cost1 = x * a + y * b

if x > y:
    price = a
else:
    price = b

cost2 = min(x, y) * 2 * c + (max(x, y) - min(x, y)) * price

cost3 = max(x,y) * 2 * c

print(min(cost1,cost2,cost3))