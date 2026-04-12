a, b, c, x, y = map(int, input().split())
c *= 2
ans1 = a * x + b * y
ans2 = c * x + b * max(0, y - x)
ans3 = c * y + a * max(0, x - y)
print(min(ans1, ans2, ans3))
