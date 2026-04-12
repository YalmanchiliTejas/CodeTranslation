
while True:
	n, a, b, c, x = map(int, input().split())
	if (n, a, b, c, x) == (0, 0, 0, 0, 0):
		break
	y = list(map(int, input().split()))

	count = -1
	i = 0
	while i < len(y):
		if y[i] == x:
			i += 1
		x = (a * x + b) % c
		count += 1
		if (10000 < count):
			count = -1
			break
	print(count)