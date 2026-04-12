a, b, c, x, y = tuple(map(lambda i: int(i), input().split()))

# 個別買い
p1 = a * x + b * y

# セット＋残りを個別
p2 = c * min(x, y) * 2 + (a * (x - y) if x > y else b * (y - x))

# セットのみ
p3 = c*max(x, y)*2

print(min(p1, p2, p3))