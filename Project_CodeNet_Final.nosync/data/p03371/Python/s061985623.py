a, b, c, x, y= map(int, input().split())

price = []
for i in range(10**5+1):
    price.append(i * 2*c + max(0,x-i) * a + max(0,y-i) * b)
print(min(price))