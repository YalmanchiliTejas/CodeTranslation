a, b, c, x, y = map(int, input().split())
ans = a * x + b * y
other = min(x, y) * 2 * c
if x > y:
    other += (x - y) * a
else:
    other += (y - x) * b
other2 = max(x, y) * 2 * c
ans = min(ans, other, other2)
print(ans)
