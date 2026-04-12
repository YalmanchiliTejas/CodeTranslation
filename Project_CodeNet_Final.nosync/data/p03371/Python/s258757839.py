a, b, c, x, y = map(int, input().split())
ans = 1e9
for i in range(max(x, y) + 1):
	cal = i * c * 2
	if x > i:
		cal += (x - i) * a
	if y > i:
		cal += (y - i) * b
	ans = min(cal, ans)
print(ans)