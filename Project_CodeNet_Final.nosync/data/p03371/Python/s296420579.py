a, b, c, x, y = [int(i) for i in input().split()]

p = [a * x + b * y, c * max(x, y) * 2]
if x != y:
    if x > y:
        p.append(c * y * 2 + a * (x-y))
    else:
        p.append(c * x * 2 + b * (y-x))

print(min(p))
