A, B, C, X, Y = map(int, input().split())
list = []

for i in range(100001):
    price = 2*C*i + A*max(0,X-i) + B*max(0,Y-i)
    list.append(price)

print(min(list))
