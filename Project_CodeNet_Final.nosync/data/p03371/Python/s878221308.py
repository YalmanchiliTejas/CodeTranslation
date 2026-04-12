a, b, c, x, y = map(int, input().split())
mp = min(x, y)
hp = mp * c * 2
hp += (x - y) * a if x > y else (y - x) * b if x < y else 0
print(min(a * x + b * y, hp, max(x, y) * c * 2))
