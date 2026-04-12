n = int(input())
price = 0
profit = 0
for i in range(1, n+1):
    price += 800
    if i % 15 == 0:
        profit += 200
print(price - profit)
