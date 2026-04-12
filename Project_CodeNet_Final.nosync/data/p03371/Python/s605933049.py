def resolve():
	a, b, c, x, y = map(int, input().split())
	opt1 = a*x + b*y
	v = a if x > y else b
	opt2 = min(x, y) * 2 * c + abs(x - y)*v
	opt3 = min(x, y)*2*c + abs(x-y)*2*c
	print(min([opt1, opt2, opt3]))
resolve()