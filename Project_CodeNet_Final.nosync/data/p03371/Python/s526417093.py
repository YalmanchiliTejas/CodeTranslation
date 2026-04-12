a, b, c, x, y = map(int, input().split())
r = []
r.append(a * x + b * y)
r.append(c * min(x, y) * 2 + (max(x, y) - min(x, y)) * (a if x > y else b))
r.append(c * max(x, y) * 2)
print(min(r))
