a, b, c, x, y = map(int, input().split())

ans = float("inf")

for i in range(10**5 + 1):
    cost = 2 * c * i + a * max(0, x - i) + b * max(0, y - i)
    ans = min(ans, cost)

print(ans)
