rgb = input()

rgb = rgb.split()

r = int(rgb[0])*100
g = int(rgb[1])*10
b = int(rgb[2])

if (r + g + b)%4 == 0:
	print('YES')
else:
	print('NO')