def resolve():
	a, b, c, x, y = map(int, input().split())
	v = float('inf')
	for i in range(10**5+1):
		t = i*c*2 + max([0, x-i])*a + max([0, y-i])*b
		v = min(v, t)
	print(v)
resolve()