# -*- coding: utf-8 -*-
a, b, c, x, y = map(int, input().split())

cost = a * x + b * y
for i in range(0, max(x, y) + 1):
    tmp = 2 * c * i
    tmp += a * max(0, x - i) + b * max(0, y - i)
    cost = min(cost, tmp)

print(cost)
