rgb = input().split()
r = rgb[0]
g = rgb[1]
b = rgb[2]

check = int(r + g + b)

if check % 4 == 0:
	print('YES')
else:
	print('NO')
