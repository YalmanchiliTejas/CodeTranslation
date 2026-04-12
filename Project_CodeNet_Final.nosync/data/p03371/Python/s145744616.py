a, b, ab, x, y = map(int, input().split())
ab *= 2
p = min(a + b, ab) * min(x, y)
if x > y:
	p += (x - y) * min(a, ab)
elif y > x:
	p += (y - x) * min(b, ab)
print(p)