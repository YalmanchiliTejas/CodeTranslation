# coding:utf-8
a, b, c, x, y = map(int, input().split())

cost = a * x + b * y
n = max(x, y)

for i in range(0, n + 1):
    tmp = 2 * i * c + max(0, x - i) * a + max(0, y - i) * b
    cost = min(tmp, cost)

print(cost)
