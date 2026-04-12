a, b, c, x, y = map(int, input().split())

candidates = []
candidates.append(a * x + b * y)
candidates.append(c * max(x, y) * 2)
candidates.append(c * min(x, y) * 2 + (a if x > y else b) * abs(x - y))

print(min(candidates))