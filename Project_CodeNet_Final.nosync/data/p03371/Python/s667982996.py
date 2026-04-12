a, b, c, x, y = map(int, input().split())
cost1 = a * x + b * y
cost2 = max(x, y) * c * 2
cost3 = min(x, y) * c * 2
if x == y:
    pass
elif x > y:
    cost3 += (x - y) * a
else:
    cost3 += (y - x) * b
print(min(cost1, cost2, cost3))
