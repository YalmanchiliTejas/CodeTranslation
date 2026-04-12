a, b, c, x, y = map(int, input().split())

cost = float("inf")
for i in range(100001):
    tc = c * i * 2 + max(a * (x - i), 0) + max(b * (y - i), 0)

    cost = min(cost, tc)

print(cost)