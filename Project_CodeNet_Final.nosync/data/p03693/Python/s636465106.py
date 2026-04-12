r, g, b = list(map(int, input().split()))

rgb = int(str(r) + str(g) + str(b))

if rgb%4 == 0:
	print('YES')
else:
	print('NO')
